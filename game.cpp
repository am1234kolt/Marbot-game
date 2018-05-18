

#include "game.h"
#include <functional>
#include "cell_t.h"
#include "path_marbot.h"
#include "manu_marbot.h"
#include <cmath>

using namespace std::placeholders;

constexpr auto k_martians_count{3};

game::game(int robot_choice):
        m_maze(true, 20),
        m_sp_gmaze{std::make_shared<gl_maze>(m_maze.get_cells(cell_t::Wall), m_maze.get_cells(cell_t::Mineral))},
        m_gmain(800, 800, 220, "MarBot 3.0"),
        m_pathfinder{m_maze},
        m_route{m_pathfinder.get_path()},
        m_map(m_route),
        m_sp_probe{std::make_shared<mineral_probe>("PROBE",
                                                   std::bind(&maze<20>::has_neighbour_minerals, &m_maze, _1, _2),
                                                   std::bind(&maze<20>::update_minerals, &m_maze, _1, _2))},
        m_kreader{},
        m_sp_grobot{std::make_shared<gl_robot>()},
        m_sp_adaptor{std::make_shared<command_adapter>(m_sp_probe)},
        m_up_robot{}, //this line should probably be removed later...
        m_sp_gmartians{},
        m_martians{}
{
    if(robot_choice==1){
        m_up_robot.reset(new path_marbot(m_map, *m_sp_probe, m_sp_adaptor->get_command_processor()));
    }
    else if(robot_choice==2){
        m_up_robot.reset(new manu_marbot(m_kreader, *m_sp_probe, m_sp_adaptor->get_command_processor()));

    }
  //  std::cout << "You selected to use " << (robot_choice == 1? "path_marbot" : "manu_marbot") << ", but it doesn't exist yet.\n";
  //  std::cout << "Don't forget to implement both classes and to add initialization of the right class in the game class constructor\n" << \
   //           "(exactly in the place where this text is being printed now)." << std::endl;





    m_sp_gmaze->set_scale(10.f);
    m_gmain.add_object(m_sp_gmaze);
    m_sp_grobot->set_scale(10.0f);
    m_gmain.add_object(m_sp_grobot);
    m_gmain.set_key_pressed_handler(m_kreader.get_key_pressed_handler());

    //just don't ask... I'm also crying at those
    auto check_cell{std::bind(&maze<20>::at, &m_maze, _1, _2)};
    auto cell_is_path = [check_cell](auto x, auto y){return check_cell(x, y) == cell_t::Path; };
    m_sp_adaptor->set_is_path_func([check_cell](auto x, auto y){return check_cell(x, y) == cell_t::Path; });

    m_sp_adaptor->set_remove_obstacle_func([this](auto x, auto y){return m_maze.clear_cell(x, y);});

    m_sp_adaptor->reset(m_maze.start().first, m_maze.start().second);
    m_sp_grobot->set_position(m_sp_adaptor->position());

    // now do the martians
    auto options{ m_maze.get_cells(cell_t::Path) };
    std::random_shuffle(options.begin(), options.end());
    constexpr auto kmin_dist{225.};
    auto calc_dist = [xr=m_maze.start().first](auto x, auto y){return (xr-x)*(xr-x) + y*y; };
    while (+m_martians.size() < k_martians_count){
        auto candidate{options.back()};
        options.pop_back();
        if (calc_dist(candidate.first, candidate.second) >= kmin_dist){
            m_martians.emplace_back(candidate.first, candidate.second);
            m_martians.back().set_is_path_func(cell_is_path);
            m_sp_gmartians.push_back(std::make_shared<gl_martian>());
            m_sp_gmartians.back()->set_scale(10.0);
            m_sp_gmartians.back()->set_position(m_martians.back().position());
            m_gmain.add_object(m_sp_gmartians.back());
        }
    }
}

void game::run() {
    auto robot_finished{false};
    auto robot_killed{false};
    while (m_gmain.render() && !robot_killed) {
        if (m_maze.updated()) {
            //check if model has changed and update the view if so
            m_sp_gmaze->update(m_maze.get_cells(cell_t::Wall),
                               m_maze.get_cells(cell_t::Mineral));
        }

        if (!m_up_robot->do_next_step()) {
            robot_finished = true;
            break;
        }

        if (m_sp_adaptor->update()){
            m_sp_grobot->set_position(m_sp_adaptor->position());
        }

        //update model for martians and graphics if needed
        for (unsigned int i=0; i < m_martians.size(); ++i){
            if (m_martians[i].update(m_sp_adaptor->position())){
                m_sp_gmartians[i]->set_position(m_martians[i].position());
            }
        }

        //check for collisions and kill if needed

        for (auto& m : m_martians){
            if (l2norm(m.position(), m_sp_adaptor->position()) < 0.8){
                robot_killed = true;
            }
        }
    }

    if (robot_killed){
        auto i{400};
        auto dr{1./i};
        auto r{0.};
        while(m_gmain.render() && (i--)){
            m_gmain.set_clear_color(r+=dr, 0.1, 0, 0.9);
        }
    }

    std::cout << m_up_robot->list_minerals();

    while (robot_finished && m_gmain.render());

}

void game::initialize() {

}
