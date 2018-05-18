

#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <cstddef>
#include <array>
#include <vector>
#include <algorithm>
#include <queue>
#include "maze.h"
#include "cell_t.h"

class pathfinder {
public:
    using Point = std::pair<int, int>;

    template<int size>
    explicit pathfinder(const maze<size>& amaze){
        find_path(amaze);
    }

    template<int size>
    void find_path(const maze<size>& amaze) {

        std::array<std::array<int, size>, size> cost;

        for (auto& col : cost){
            for (unsigned int i = 0; i < col.size(); ++i) {
                col[i] = INT_MAX;
            }
        }

        std::array<std::array<Point, size>, size> came_from;

        auto cmpr = [&](Point a, Point b){return cost[a.first][a.second] < cost[b.first][b.second]; };
        std::priority_queue<Point, std::vector<Point>, decltype(cmpr)> frontier(cmpr);

        frontier.emplace(amaze.start());
        cost[amaze.start().first][0] = 0;
        came_from[amaze.start().first][0] = std::make_pair(-1, -1);

        while(!frontier.empty()){
            auto node = frontier.top();
            frontier.pop();
            if (node.first == amaze.goal().first && node.second == size - 1) break;
            for (Point neighbour : neighbours(amaze, node.first, node.second)){
                auto new_cost = cost[node.first][node.second] + 1;

                if (new_cost < cost[neighbour.first][neighbour.second]){
                    cost[neighbour.first][neighbour.second] = new_cost;
                    frontier.emplace(neighbour.first, neighbour.second);
                    came_from[neighbour.first][neighbour.second] = node;
                }
            }
        }

        Point current{std::make_pair(amaze.goal().first, size-1)};
        while (current.first != -1 && current.second != -1){
            m_path.push_back(current);
       //     maze[current.first][current.second] = cell_type::Route;
            current = came_from[current.first][current.second];
        }

        std::reverse(m_path.begin(), m_path.end());
    }
    const std::vector<Point>& get_path() const {return m_path; }
private:


    std::vector<Point> m_path;

    template<int size>
    std::vector<Point> neighbours(const maze<size>& amaze, int x, int y){
        std::vector<Point> result;

        if (x > 0 && amaze.at(x-1, y) == cell_t::Path) result.emplace_back(x-1, y);
        if (x < size-1 && amaze.at(x+1, y) == cell_t::Path) result.emplace_back(x+1, y);

        if (y > 0 && amaze.at(x, y-1) == cell_t::Path) result.emplace_back(x, y-1);
        if (y < size - 1 && amaze.at(x, y+1) == cell_t::Path) result.emplace_back(x, y+1);
        return result;
    }
};


#endif
