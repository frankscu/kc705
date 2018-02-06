#ifndef DAQTEST_H
#define DAQTEST_H

#include "JadeManager.hh"
#include "JadeRegCtrl.hh"
#include <iostream>
#include <chrono>
#include <thread>
#include <ctime>

class daqTest{
    public:
        daqTest();
        ~daqTest();
       
        void initial(); 
        void set_input(std::string);
        void set_output();
        void set_output_file(std::string);
        void start_run();
        void stop_run();
        void set_time_run(std::string time);
        void print_info();
    
    private:
        
        std::string opt_data_input;
        std::string opt_reg;
        std::string opt_data_output;      
        std::string opt_time_run; 
        std::string opt_ev_print; 
        std::string data_output_path;

        size_t time_run;
        size_t ev_print;

        JadeRegCtrl* preg;
        JadeManager* pman;

};

#endif //DAQTEST_H
