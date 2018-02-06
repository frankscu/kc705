#include "daqTest.hh"

using namespace std::chrono_literals;

daqTest::daqTest():opt_data_input("//./xillybus_read_32"),opt_reg("//./xillybus_mem_8"),opt_data_output("output"),opt_time_run("60"),opt_ev_print("10000"),data_output_path("test")
{
}

daqTest::~daqTest()
{
}

void daqTest::set_time_run(std::string time){
    opt_time_run = time;
}

void daqTest::initial(){
    time_run = std::stoul(opt_time_run);
    ev_print = std::stoul(opt_ev_print);

    preg = new JadeRegCtrl(opt_reg);
    preg->WriteByte(4, 15);
    std::this_thread::sleep_for(100ms);
    preg->WriteByte(3, 15);
    pman = new JadeManager();
}

void daqTest::set_input(std::string inPipe){
    opt_data_input = inPipe;
}

void daqTest::set_output_file(std::string dataOut){
    opt_data_output = dataOut;
    set_output();
}

void daqTest::set_output(){
    std::time_t time_now = std::time(nullptr);

    char time_buff[13];
    time_buff[12] = 0;
    std::strftime(time_buff, sizeof(time_buff),
            "%y%m%d%H%M%S", std::localtime(&time_now));
    std::string time_str(time_buff);
    data_output_path = opt_data_output+"_"+time_str +".df";
}

void daqTest::print_info(){
    std::cout<< "{opt_data_input:"<<opt_data_input<<"}"<<std::endl;
    std::cout<< "{opt_reg:"<<opt_reg<<"}"<<std::endl;
    std::cout<< "{data_output_path:"<<data_output_path<<"}"<<std::endl;
    std::cout<< "{time_run:"<<time_run<<"}"<<std::endl;
    std::cout<< "{ev_print:"<<ev_print<<"}"<<std::endl;
} 

void daqTest::start_run(){
    pman->SetReader(std::make_unique<JadeRead>(opt_data_input, ""));
    pman->SetFilter(std::make_unique<JadeFilter>(std::to_string(ev_print)));
    pman->SetWriter(std::make_unique<JadeWrite>(data_output_path, ""));
    pman->Start();
    preg->WriteByte(4, 15);
}

void daqTest::stop_run(){
    std::this_thread::sleep_for(std::chrono::milliseconds(time_run));
    pman->Stop();
}
