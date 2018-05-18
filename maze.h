

#ifndef MAZE_H
#define MAZE_H

#include <random>
#include <array>
#include <chrono>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <tuple>

#include "cell_t.h"

template <int maze_size=20>
class maze {
public:
    maze(bool generate_maze=false, int minerals=0):
        m_maze{},
        m_generator{static_cast<unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()) },
        m_distro{1, maze_size-2},
        m_start{-1},
        m_stop{-1},
        m_updated{false}
    {
        cleanup();
        if (generate_maze){
            _generate();
            if (minerals > 0){
                add_minerals(minerals);
            }
        }
    }


    using Position = std::pair<int, int>;

    constexpr int size() const {return maze_size; }

    cell_t at(int x, int y) const { return m_maze[x][y]; }

    Position start() const { return std::make_pair(m_start, 0); }
    Position goal() const {return std::make_pair(m_stop, maze_size - 1); }

    void generate() { _generate(); }
    void add_minerals(int count) { _put_minerals(count); }

    bool updated() {
        auto r{m_updated};
        m_updated = false;
        return r;
    }

    std::string to_string() {

        std::ostringstream output;

        for (int j = maze_size - 1; j >= 0; j--) {
            for (int i = 0; i < maze_size; ++i) {
                if (at(i, j) == cell_t::Wall)
                    output << "X";
                else if (at(i, j) == cell_t::Route)
                    output << "o";
                    else if (at(i, j) == cell_t::Mineral)
                    output << "$";
                else
                    output << ".";
            }
            output << "\n";
        }
        return output.str();
    }

    std::vector<Position> get_cells(cell_t kind){
        std::vector<Position> result;

        for (int j = maze_size - 1; j >= 0; j--) {
            for (int i = 0; i < maze_size; ++i) {
                if (at(i,j) == kind){
                    result.emplace_back(i, j);
                }
            }
        }
        return result;
    }

    bool has_neighbour_minerals(int x, int y) const{
        return mineral_neighbours(x, y).size() > 0;
    }

    bool clear_cell(int x, int y){
        if (x == 0 || x == maze_size - 1 || y == 0 || y == maze_size - 1){
            return false;
        }

        if (m_maze[x][y] == cell_t::Wall || m_maze[x][y] == cell_t::Mineral){
            m_maze[x][y] = cell_t::Path;
            return (m_updated = true);
        }
        return false;
    }

    void update_minerals(int x, int y){
        auto neigh{mineral_neighbours(x, y)};
        if (!neigh.empty()){
            m_maze[neigh.front().first][neigh.front().second] = cell_t::Wall;
            m_updated = true;
        }
    }

    using neighbours_t = std::tuple<cell_t, cell_t, cell_t, cell_t>;

    neighbours_t neighbours(int x, int y){
        auto north = y < maze_size - 1? m_maze[x][y+1] : cell_t::None;
        auto south = y > 0? m_maze[x][y-1] : cell_t::None;
        auto east = x < maze_size - 1? m_maze[x+1][y] : cell_t::None;
        auto west = x > 0? m_maze[x-1][y] : cell_t::None;

        return std::make_tuple(north, east, south, west);
    }

private :
    std::array<std::array<cell_t, maze_size>, maze_size> m_maze;
    std::mt19937 m_generator;
    std::uniform_int_distribution<> m_distro;
    int m_start;
    int m_stop;
    bool m_updated;

    void cleanup(){
        //clean up first
        for (auto& col : m_maze){
            for (auto& cell : col){
                cell = cell_t::Wall;
            }
        }
    }

    // counts the neighbours which are not wall
    int count_open_neighbours(int x, int y){
        int count{4};

        if (x > 0 && m_maze[x-1][y] == cell_t::Wall) count--;
        else if (x == 0) count--;

        if (x < maze_size - 1 && m_maze[x+1][y] == cell_t::Wall) count--;
        else if (x == maze_size - 1) count--;

        if (y > 0 && m_maze[x][y-1] == cell_t::Wall) count--;
        else if (y == 0) count--;

        if (y < maze_size - 1 && m_maze[x][y+1] == cell_t::Wall) count--;
        else if (y == maze_size - 1) count--;
        return count;
    }

    std::vector<Position> mineral_neighbours(int x, int y) const{
        std::vector<Position> result;

        if (x > 0 && m_maze[x-1][y] == cell_t::Mineral)
            result.emplace_back(x-1, y);
        if (x < maze_size - 1 && m_maze[x+1][y] == cell_t::Mineral)
            result.emplace_back(x+1, y);
        if (y > 0 && m_maze[x][y-1] == cell_t::Mineral)
            result.emplace_back(x, y-1);
        if (y < maze_size - 1 && m_maze[x][y+1] == cell_t::Mineral)
            result.emplace_back(x, y+1);

        return result;
    }

    // gets the move options from current cell
    std::vector<Position> move_options(int x, int y, bool exclude_last_row=false){
        //the idea is, you can only have one neighbour to be a possible option
        std::vector<Position> result;

        if (exclude_last_row && y != maze_size - 1) {
            if (x > 1 && count_open_neighbours(x - 1, y) == 1) {
                result.emplace_back(x - 1, y);
            }
            if (x < maze_size - 2 && count_open_neighbours(x + 1, y) == 1) {
                result.emplace_back(x + 1, y);
            }
        }
        if (y > 0 && count_open_neighbours(x, y-1) == 1){
            result.emplace_back(x, y-1);
        }

        if (y < maze_size - 2 && count_open_neighbours(x, y+1) == 1){
            result.emplace_back(x, y+1);
        }
        return result;
    }

    void _generate(){

        auto set_cell = [&](auto x, auto y, auto t){ m_maze[x][y] = t; };

        std::vector<Position> path;

        // pick a random starting cell
        auto start_x = m_distro(m_generator);
        set_cell(start_x, maze_size - 1, cell_t::Path);

        path.emplace_back(start_x, maze_size - 1);
        auto cont_count = 1500;
        auto stop_x = -1;
        while( cont_count > 0){

            if (stop_x != -1) cont_count--;

            if (m_distro(m_generator) > 0.1)
                std::random_shuffle(path.end() - path.size()/2, path.end());
            auto current = path.back();

            if (current.second == 0){
                path.pop_back();
                continue;
            }

            auto nexts = move_options(current.first, current.second, true);

            if (nexts.empty()){
                path.pop_back();
                continue;
            }

            std::random_shuffle(nexts.begin(), nexts.end());
            auto next = nexts.front();

//            std::cout << "nexts all : ";
//            for (auto n : nexts){
//                std::cout << "[" << n.first << ", " << n.second << " ], ";
//            }
//
//            std::cout << "\n";
//
//
//            std::cout << "next: " << next.first << ", " << next.second << "\n";

            path.push_back(next);

            if (next.second == 0){
                if (stop_x == -1) {
                    stop_x = next.first;
                    set_cell(next.first, next.second, cell_t::Path);
                }
                else if (abs(stop_x - start_x) < abs(next.first - start_x)){
                    set_cell(stop_x, 0, cell_t::Wall);
                    stop_x = next.first;
                    set_cell(next.first, next.second, cell_t::Path);
                }
            } else{
                set_cell(next.first, next.second, cell_t::Path);
            }
        }

        //yes the maze gets reversed here
        m_start = stop_x;
        m_stop = start_x;
    }

    void _put_minerals(int count){
        std::uniform_int_distribution<> distro(0, maze_size-1);

        while (count){
            auto x = distro(m_generator);
            auto y = distro(m_generator);
            if (x == 0 || x == maze_size - 1 || y == 0 || y == maze_size - 1)
                continue;
            if (m_maze[x][y] == cell_t::Wall){
                if (count_open_neighbours(x, y) > 0) {
                    m_maze[x][y] = cell_t::Mineral;
                    count--;
                }
            }
        }
    }
};

#endif
