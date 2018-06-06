#ifndef GUIMONITOR_HH
#define GUIMONITOR_HH

#include "JadeMonitor.hh"
#include "JadeOption.hh"
#include <TH1.h>
#include <TH2.h>
#include <TRandom.h>
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <mutex>
#include <vector>

class GUIMonitor : public JadeMonitor {
  public:
  GUIMonitor(const JadeOption& options);
  void Monitor(JadeDataFrameSP df);
  void Reset();
  std::shared_ptr<TH2F> GetADCMap();
  std::shared_ptr<TH1F> GetADCHist();

  private:
  JadeOption m_opt;
  size_t m_ev_get;
  size_t m_ev_num;
  int m_col;
  int m_row;
  int m_thr; //*
  std::string m_curr_time;
  JadeDataFrameSP m_df;
  JadeDataFrameSP m_u_df;
  std::mutex m_mx_get;
  std::mutex m_mx_set;
  uint32_t m_nx;
  uint32_t m_ny;

  std::shared_ptr<TH2F> m_adc_map;
  std::shared_ptr<TH2F> m_adc_map_clone;
  std::shared_ptr<TH1F> m_adc_hist;
  std::shared_ptr<TH1F> m_adc_hist_clone;
};
#endif
