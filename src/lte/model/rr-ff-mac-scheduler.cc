/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2011 Centre Tecnologic de Telecomunicacions de Catalunya (CTTC)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author: Marco Miozzo <marco.miozzo@cttc.es>
 */

#include <ns3/log.h>
#include <ns3/pointer.h>

#include "lte-amc.h"
#include "rr-ff-mac-scheduler.h"

NS_LOG_COMPONENT_DEFINE ("RrFfMacScheduler");

namespace ns3 {

int Type0AllocationRbg[4] = {
  10,       // RGB size 1
  26,       // RGB size 2
  63,       // RGB size 3
  110       // RGB size 4
};  // see table 7.1.6.1-1 of 36.213


NS_OBJECT_ENSURE_REGISTERED (RrFfMacScheduler);


class RrSchedulerMemberCschedSapProvider : public FfMacCschedSapProvider
{
public:
  RrSchedulerMemberCschedSapProvider (RrFfMacScheduler* scheduler);

  // inherited from FfMacCschedSapProvider
  virtual void CschedCellConfigReq (const struct CschedCellConfigReqParameters& params);
  virtual void CschedUeConfigReq (const struct CschedUeConfigReqParameters& params);
  virtual void CschedLcConfigReq (const struct CschedLcConfigReqParameters& params);
  virtual void CschedLcReleaseReq (const struct CschedLcReleaseReqParameters& params);
  virtual void CschedUeReleaseReq (const struct CschedUeReleaseReqParameters& params);

private:
  RrSchedulerMemberCschedSapProvider ();
  RrFfMacScheduler* m_scheduler;
};

RrSchedulerMemberCschedSapProvider::RrSchedulerMemberCschedSapProvider ()
{
}

RrSchedulerMemberCschedSapProvider::RrSchedulerMemberCschedSapProvider (RrFfMacScheduler* scheduler) : m_scheduler (scheduler)
{
}


void
RrSchedulerMemberCschedSapProvider::CschedCellConfigReq (const struct CschedCellConfigReqParameters& params)
{
  m_scheduler->DoCschedCellConfigReq (params);
}

void
RrSchedulerMemberCschedSapProvider::CschedUeConfigReq (const struct CschedUeConfigReqParameters& params)
{
  m_scheduler->DoCschedUeConfigReq (params);
}


void
RrSchedulerMemberCschedSapProvider::CschedLcConfigReq (const struct CschedLcConfigReqParameters& params)
{
  m_scheduler->DoCschedLcConfigReq (params);
}

void
RrSchedulerMemberCschedSapProvider::CschedLcReleaseReq (const struct CschedLcReleaseReqParameters& params)
{
  m_scheduler->DoCschedLcReleaseReq (params);
}

void
RrSchedulerMemberCschedSapProvider::CschedUeReleaseReq (const struct CschedUeReleaseReqParameters& params)
{
  m_scheduler->DoCschedUeReleaseReq (params);
}




class RrSchedulerMemberSchedSapProvider : public FfMacSchedSapProvider
{
public:
  RrSchedulerMemberSchedSapProvider (RrFfMacScheduler* scheduler);

  // inherited from FfMacSchedSapProvider
  virtual void SchedDlRlcBufferReq (const struct SchedDlRlcBufferReqParameters& params);
  virtual void SchedDlPagingBufferReq (const struct SchedDlPagingBufferReqParameters& params);
  virtual void SchedDlMacBufferReq (const struct SchedDlMacBufferReqParameters& params);
  virtual void SchedDlTriggerReq (const struct SchedDlTriggerReqParameters& params);
  virtual void SchedDlRachInfoReq (const struct SchedDlRachInfoReqParameters& params);
  virtual void SchedDlCqiInfoReq (const struct SchedDlCqiInfoReqParameters& params);
  virtual void SchedUlTriggerReq (const struct SchedUlTriggerReqParameters& params);
  virtual void SchedUlNoiseInterferenceReq (const struct SchedUlNoiseInterferenceReqParameters& params);
  virtual void SchedUlSrInfoReq (const struct SchedUlSrInfoReqParameters& params);
  virtual void SchedUlMacCtrlInfoReq (const struct SchedUlMacCtrlInfoReqParameters& params);
  virtual void SchedUlCqiInfoReq (const struct SchedUlCqiInfoReqParameters& params);


private:
  RrSchedulerMemberSchedSapProvider ();
  RrFfMacScheduler* m_scheduler;
};



RrSchedulerMemberSchedSapProvider::RrSchedulerMemberSchedSapProvider ()
{
}


RrSchedulerMemberSchedSapProvider::RrSchedulerMemberSchedSapProvider (RrFfMacScheduler* scheduler)
  : m_scheduler (scheduler)
{
}

void
RrSchedulerMemberSchedSapProvider::SchedDlRlcBufferReq (const struct SchedDlRlcBufferReqParameters& params)
{
  m_scheduler->DoSchedDlRlcBufferReq (params);
}

void
RrSchedulerMemberSchedSapProvider::SchedDlPagingBufferReq (const struct SchedDlPagingBufferReqParameters& params)
{
  m_scheduler->DoSchedDlPagingBufferReq (params);
}

void
RrSchedulerMemberSchedSapProvider::SchedDlMacBufferReq (const struct SchedDlMacBufferReqParameters& params)
{
  m_scheduler->DoSchedDlMacBufferReq (params);
}

void
RrSchedulerMemberSchedSapProvider::SchedDlTriggerReq (const struct SchedDlTriggerReqParameters& params)
{
  m_scheduler->DoSchedDlTriggerReq (params);
}

void
RrSchedulerMemberSchedSapProvider::SchedDlRachInfoReq (const struct SchedDlRachInfoReqParameters& params)
{
  m_scheduler->DoSchedDlRachInfoReq (params);
}

void
RrSchedulerMemberSchedSapProvider::SchedDlCqiInfoReq (const struct SchedDlCqiInfoReqParameters& params)
{
  m_scheduler->DoSchedDlCqiInfoReq (params);
}

void
RrSchedulerMemberSchedSapProvider::SchedUlTriggerReq (const struct SchedUlTriggerReqParameters& params)
{
  m_scheduler->DoSchedUlTriggerReq (params);
}

void
RrSchedulerMemberSchedSapProvider::SchedUlNoiseInterferenceReq (const struct SchedUlNoiseInterferenceReqParameters& params)
{
  m_scheduler->DoSchedUlNoiseInterferenceReq (params);
}

void
RrSchedulerMemberSchedSapProvider::SchedUlSrInfoReq (const struct SchedUlSrInfoReqParameters& params)
{
  m_scheduler->DoSchedUlSrInfoReq (params);
}

void
RrSchedulerMemberSchedSapProvider::SchedUlMacCtrlInfoReq (const struct SchedUlMacCtrlInfoReqParameters& params)
{
  m_scheduler->DoSchedUlMacCtrlInfoReq (params);
}

void
RrSchedulerMemberSchedSapProvider::SchedUlCqiInfoReq (const struct SchedUlCqiInfoReqParameters& params)
{
  m_scheduler->DoSchedUlCqiInfoReq (params);
}





RrFfMacScheduler::RrFfMacScheduler ()
  :   m_cschedSapUser (0),
    m_schedSapUser (0),
    m_schedTtiDelay (2), // WILD ACK: based on a m_macChTtiDelay = 1 
    m_nextRntiDl (0),
    m_nextRntiUl (0)
{
  m_cschedSapProvider = new RrSchedulerMemberCschedSapProvider (this);
  m_schedSapProvider = new RrSchedulerMemberSchedSapProvider (this);
}

RrFfMacScheduler::~RrFfMacScheduler ()
{
  NS_LOG_FUNCTION (this);
}

void
RrFfMacScheduler::DoDispose ()
{
  NS_LOG_FUNCTION (this);
  delete m_cschedSapProvider;
  delete m_schedSapProvider;
}

TypeId
RrFfMacScheduler::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::RrFfMacScheduler")
    .SetParent<FfMacScheduler> ()
    .AddConstructor<RrFfMacScheduler> ();
  return tid;
}



void
RrFfMacScheduler::SetFfMacCschedSapUser (FfMacCschedSapUser* s)
{
  m_cschedSapUser = s;
}

void
RrFfMacScheduler::SetFfMacSchedSapUser (FfMacSchedSapUser* s)
{
  m_schedSapUser = s;
}

FfMacCschedSapProvider*
RrFfMacScheduler::GetFfMacCschedSapProvider ()
{
  return m_cschedSapProvider;
}

FfMacSchedSapProvider*
RrFfMacScheduler::GetFfMacSchedSapProvider ()
{
  return m_schedSapProvider;
}

void
RrFfMacScheduler::DoCschedCellConfigReq (const struct FfMacCschedSapProvider::CschedCellConfigReqParameters& params)
{
  NS_LOG_FUNCTION (this);
  // Read the subset of parameters used
  m_cschedCellConfig = params;
  FfMacCschedSapUser::CschedUeConfigCnfParameters cnf;
  cnf.m_result = SUCCESS;
  m_cschedSapUser->CschedUeConfigCnf (cnf);
  return;
}

void
RrFfMacScheduler::DoCschedUeConfigReq (const struct FfMacCschedSapProvider::CschedUeConfigReqParameters& params)
{
  NS_LOG_FUNCTION (this);
  // Not used at this stage
  return;
}

void
RrFfMacScheduler::DoCschedLcConfigReq (const struct FfMacCschedSapProvider::CschedLcConfigReqParameters& params)
{
  NS_LOG_FUNCTION (this);
  // Not used at this stage
  return;
}

void
RrFfMacScheduler::DoCschedLcReleaseReq (const struct FfMacCschedSapProvider::CschedLcReleaseReqParameters& params)
{
  NS_LOG_FUNCTION (this);
  // TODO: Implementation of the API
  return;
}

void
RrFfMacScheduler::DoCschedUeReleaseReq (const struct FfMacCschedSapProvider::CschedUeReleaseReqParameters& params)
{
  NS_LOG_FUNCTION (this);
  // TODO: Implementation of the API
  return;
}


void
RrFfMacScheduler::DoSchedDlRlcBufferReq (const struct FfMacSchedSapProvider::SchedDlRlcBufferReqParameters& params)
{
  NS_LOG_FUNCTION (this << params.m_rnti << (uint32_t) params.m_logicalChannelIdentity);
  // API generated by RLC for updating RLC parameters on a LC (tx and retx queues)
  std::vector<FfMacSchedSapProvider::SchedDlRlcBufferReqParameters>::iterator it;
  bool newLc = true;
  for (it = m_rlcBufferReq.begin (); it != m_rlcBufferReq.end (); it++)
    {
      // remove old entries of this UE-LC
      if (((*it).m_rnti == params.m_rnti)&&((*it).m_logicalChannelIdentity == params.m_logicalChannelIdentity))
        {
          m_rlcBufferReq.erase (it);
          newLc = false;
        }
    }
  // add the new parameters
  m_rlcBufferReq.insert (it, params);
  // initialize statistics of the flow in case of new flows
  if (newLc == true)
    {
      m_p10CqiRxed.insert ( std::pair<uint16_t, uint8_t > (params.m_rnti, 1)); // only codeword 0 at this stage (SISO)
      // initialized to 1 (i.e., the lowest value for transmitting a signal)
    }

  return;
}

void
RrFfMacScheduler::DoSchedDlPagingBufferReq (const struct FfMacSchedSapProvider::SchedDlPagingBufferReqParameters& params)
{
  NS_LOG_FUNCTION (this);
  // TODO: Implementation of the API
  return;
}

void
RrFfMacScheduler::DoSchedDlMacBufferReq (const struct FfMacSchedSapProvider::SchedDlMacBufferReqParameters& params)
{
  NS_LOG_FUNCTION (this);
  // TODO: Implementation of the API
  return;
}

int
RrFfMacScheduler::GetRbgSize (int dlbandwidth)
{
  for (int i = 0; i < 4; i++)
    {
      if (dlbandwidth < Type0AllocationRbg[i])
        {
          return (i + 1);
        }
    }

  return (-1);
}


void
RrFfMacScheduler::DoSchedDlTriggerReq (const struct FfMacSchedSapProvider::SchedDlTriggerReqParameters& params)
{
  NS_LOG_FUNCTION (this << " Frame no. " << (params.m_sfnSf>>4) << " subframe no. " << (0xF & params.m_sfnSf));
  // API generated by RLC for triggering the scheduling of a DL subframe

  // Get the actual active flows (queue!=0)
  std::vector<FfMacSchedSapProvider::SchedDlRlcBufferReqParameters>::iterator it;
  int nflows = 0;
  std::map <uint16_t,uint8_t> lcActivesPerRnti;
  std::map <uint16_t,uint8_t>::iterator itLcRnti;
  for (it = m_rlcBufferReq.begin (); it != m_rlcBufferReq.end (); it++)
    {
      // remove old entries of this UE-LC
      if ( ((*it).m_rlcTransmissionQueueSize > 0)
           || ((*it).m_rlcRetransmissionQueueSize > 0)
           || ((*it).m_rlcStatusPduSize > 0) )
        {
          std::map <uint16_t,uint8_t>::iterator itCqi = m_p10CqiRxed.find ((*it).m_rnti);
          if (itCqi != m_p10CqiRxed.end ())
            {
              if ((*itCqi).second != 0)
                {
                  // CQI == 0 means "out of range" (see table 7.2.3-1 of 36.213)
                  nflows++;
                  itLcRnti = lcActivesPerRnti.find ((*it).m_rnti);
                  if (itLcRnti!=lcActivesPerRnti.end ())
                    {
                      (*itLcRnti).second++;
                    }
                  else
                    {
                      lcActivesPerRnti.insert (std::pair<uint16_t, uint8_t > ((*it).m_rnti, 1));
                    }
                }
            }
        }
    }
   
  if (nflows == 0)
    {
      return;
    }
  // Divide the resource equally among the active users according to
  // Resource allocation type 0 (see sec 7.1.6.1 of 36.213)
  int rbgSize = GetRbgSize (m_cschedCellConfig.m_dlBandwidth);
  int rbgNum = m_cschedCellConfig.m_dlBandwidth / rbgSize;
  int rbgPerFlow = rbgNum / nflows;
  if (rbgPerFlow == 0)
    {
      rbgPerFlow = 1;                // at least 1 rbg per flow (till available resource)
    }
  int rbgAllocated = 0;

  FfMacSchedSapUser::SchedDlConfigIndParameters ret;
  // round robin assignment to all UE-LC registered starting from the subsequent of the one
  // served last scheduling trigger
  //NS_LOG_DEBUG (this << " next to be served " << m_nextRntiDl << " nflows " << nflows);
  if (m_nextRntiDl!=0)
    {
      for (it = m_rlcBufferReq.begin (); it != m_rlcBufferReq.end (); it++)
        {
          if ((*it).m_rnti == m_nextRntiDl)    
          {
            break;
          }
        }
        
        if (it == m_rlcBufferReq.end ())
        {
          NS_LOG_ERROR (this << " no user found");
        }
    }
  else
    {
      it = m_rlcBufferReq.begin ();
      m_nextRntiDl = (*it).m_rnti;
    }
  do
    {
      itLcRnti = lcActivesPerRnti.find ((*it).m_rnti);
      if (itLcRnti==lcActivesPerRnti.end ())
      {
        // skip this entry
        it++;
        if (it==m_rlcBufferReq.end ())
          {
            // restart from the first
            it = m_rlcBufferReq.begin ();
          }
        continue;
      }
      int lcNum = (*itLcRnti).second;
      // create new BuildDataListElement_s for this RNTI
      BuildDataListElement_s newEl;
      newEl.m_rnti = (*it).m_rnti;
      // create the DlDciListElement_s
      DlDciListElement_s newDci;
      newDci.m_rnti = (*it).m_rnti;
      newDci.m_resAlloc = 0;
      newDci.m_rbBitmap = 0;
      std::map <uint16_t,uint8_t>::iterator itCqi = m_p10CqiRxed.find (newEl.m_rnti);
      if (itCqi == m_p10CqiRxed.end ())
        {
          newDci.m_mcs.push_back (0); // no info on this user -> lowest MCS
        }
      else
        {
          newDci.m_mcs.push_back ( LteAmc::GetMcsFromCqi ((*itCqi).second) );
        }
      // group the LCs of this RNTI
      std::vector <struct RlcPduListElement_s> newRlcPduLe;
      int totRbg = lcNum * rbgPerFlow;
      int tbSize = (LteAmc::GetTbSizeFromMcs (newDci.m_mcs.at (0), totRbg * rbgSize) / 8);
//       NS_LOG_DEBUG (this << "Allocate user " << newEl.m_rnti << " LCs " << (uint16_t)(*itLcRnti).second << " bytes " << tbSize << " PRBs " << totRbg * rbgSize << " mcs " << (uint16_t) newDci.m_mcs.at (0));
      uint16_t rlcPduSize = tbSize / lcNum;
      for (int i = 0; i < lcNum ; i++)
        {
          RlcPduListElement_s newRlcEl;
          newRlcEl.m_logicalChannelIdentity = (*it).m_logicalChannelIdentity;
          //NS_LOG_DEBUG (this << "LCID " << (uint32_t) newRlcEl.m_logicalChannelIdentity << " size " << rlcPduSize);
          newRlcEl.m_size = rlcPduSize;
          newRlcPduLe.push_back (newRlcEl);
          it++;
          if (it==m_rlcBufferReq.end ())
            {
              // restart from the first
              it = m_rlcBufferReq.begin ();
            }
        }
      uint32_t rbgMask = 0;
      for (int i = 0; i < totRbg; i++)
        {
          rbgMask = rbgMask + (0x1 << rbgAllocated);
          rbgAllocated++;
        }
      newDci.m_rbBitmap = rbgMask; // (32 bit bitmap see 7.1.6 of 36.213)

      int nbOfTbsInNewDci = 1;  // SISO -> only one TB
      for (int i = 0; i < nbOfTbsInNewDci; i++)
        {
          newDci.m_tbsSize.push_back (tbSize);
          newDci.m_ndi.push_back (1); // TBD (new data indicator)
          newDci.m_rv.push_back (0); // TBD (redundancy version)
        }
      newEl.m_dci = newDci;
      // ...more parameters -> ignored in this version




      newEl.m_rlcPduList.push_back (newRlcPduLe);
      ret.m_buildDataList.push_back (newEl);
      if (rbgAllocated == rbgNum)
        {
          //NS_LOG_DEBUG (this << " FULL " << (*it).m_rnti);
          m_nextRntiDl = (*it).m_rnti; // store last RNTI served
          break;                       // no more RGB to be allocated
        }
    } while ((*it).m_rnti != m_nextRntiDl);

  ret.m_nrOfPdcchOfdmSymbols = 1;   // TODO: check correct value according the DCIs txed

  m_schedSapUser->SchedDlConfigInd (ret);
  return;
}

void
RrFfMacScheduler::DoSchedDlRachInfoReq (const struct FfMacSchedSapProvider::SchedDlRachInfoReqParameters& params)
{
  NS_LOG_FUNCTION (this);
  // TODO: Implementation of the API
  return;
}

void
RrFfMacScheduler::DoSchedDlCqiInfoReq (const struct FfMacSchedSapProvider::SchedDlCqiInfoReqParameters& params)
{
  NS_LOG_FUNCTION (this);

  std::map <uint16_t,uint8_t>::iterator it;
  for (unsigned int i = 0; i < params.m_cqiList.size (); i++)
    {
      if ( params.m_cqiList.at (i).m_cqiType == CqiListElement_s::P10 )
        {
          // wideband CQI reporting
          std::map <uint16_t,uint8_t>::iterator it;
          uint16_t rnti = params.m_cqiList.at (i).m_rnti;
          it = m_p10CqiRxed.find (rnti);
          if (it == m_p10CqiRxed.end ())
            {
              // create the new entry
              m_p10CqiRxed.insert ( std::pair<uint16_t, uint8_t > (rnti, params.m_cqiList.at (i).m_wbCqi.at (0)) ); // only codeword 0 at this stage (SISO)
            }
          else
            {
              // update the CQI value
              (*it).second = params.m_cqiList.at (i).m_wbCqi.at (0);
            }
        }
      else if ( params.m_cqiList.at (i).m_cqiType == CqiListElement_s::A30 )
        {
          // subband CQI reporting high layer configured 
          // Not used by RR Scheduler
        }
      else
        {
          NS_LOG_ERROR (this << " CQI type unknown");
        }
    }

  return;
}

void
RrFfMacScheduler::DoSchedUlTriggerReq (const struct FfMacSchedSapProvider::SchedUlTriggerReqParameters& params)
{
  NS_LOG_FUNCTION (this << " Frame no. " << (params.m_sfnSf>>4) << " subframe no. " << (0xF & params.m_sfnSf));
  // TODO: Implementation of the API
  
  std::map <uint16_t,uint8_t>::iterator it; 
  int nflows = 0;
  
  for (it = m_ceBsrRxed.begin (); it != m_ceBsrRxed.end (); it++)
    {
      // remove old entries of this UE-LC
      if ((*it).second > 0)
      {
        nflows++;
      }
    }
  
  if (nflows==0)
  {
    return ;  // no flows to be scheduled
  } 
   
  
  // Divide the resource equally among the active users starting from the subsequent one served last scheduling trigger
  int rbPerFlow = m_cschedCellConfig.m_ulBandwidth / nflows;
  if (rbPerFlow == 0)
  {
    rbPerFlow = 1;                // at least 1 rbg per flow (till available resource)
  }
  int rbAllocated = 0;
  
  FfMacSchedSapUser::SchedUlConfigIndParameters ret;
  std::vector <uint16_t> rbgAllocationMap;
  NS_LOG_DEBUG (this << " Next is be " << m_nextRntiUl);
  if (m_nextRntiUl!=0)
    {
      for (it = m_ceBsrRxed.begin (); it != m_ceBsrRxed.end (); it++)
        {
          if ((*it).first == m_nextRntiUl)    
            {
              break;
            }
        }
        NS_LOG_DEBUG (this << " found  " << (*it).first);
        if (it == m_ceBsrRxed.end ())
          {
            NS_LOG_ERROR (this << " no user found");
          }
    }
  else
  {
    it = m_ceBsrRxed.begin ();
    m_nextRntiUl = (*it).first;
  }
  //for (it = m_ceBsrRxed.begin (); it != m_ceBsrRxed.end (); it++)
  do
    {
      if (rbAllocated + rbPerFlow > m_cschedCellConfig.m_ulBandwidth)
        {
          // limit to physical resources last resource assignment
          rbPerFlow = m_cschedCellConfig.m_ulBandwidth - rbAllocated;
        }
       // store info on allocation for managing ul-cqi interpretation
      for (int i = 0; i < rbPerFlow; i++)
        {
        	rbgAllocationMap.push_back ((*it).first);
        }
      UlDciListElement_s uldci;
      uldci.m_rnti = (*it).first;
      uldci.m_rbStart = rbAllocated;
      uldci.m_rbLen = rbPerFlow;
      rbAllocated += rbPerFlow;
      std::map <uint16_t, std::vector <double> >::iterator itCqi = m_ueCqi.find ((*it).first);
      int cqi = 0;
      if (itCqi == m_ueCqi.end ())
        {
        	// no cqi info about this UE
          uldci.m_mcs = 0; // MCS 0 -> UL-AMC TBD
          //NS_LOG_DEBUG (this << " UE does not have ULCQI " << (*it).first );
        }
      else
        {
        	// take the lowest CQI value (worst RB)
        	double minSinr = (*itCqi).second.at(uldci.m_rbStart);
        	for (uint16_t i = uldci.m_rbStart; i < uldci.m_rbStart + uldci.m_rbLen; i++)
        	  {
        	  	//NS_LOG_DEBUG (this << " UE " << (*it).first << " has CQI " << (*itCqi).second.at(i));
        	  	if ((*itCqi).second.at(i) < minSinr)
        	  	  {
        	  	  	minSinr = (*itCqi).second.at(i);
        	  	  }
        	  }
        	// translate SINR -> cqi: WILD ACK: same as DL
        	double s = log2 ( 1 + (
                          pow (10, minSinr / 10 )  /
                          ( (-log (5.0 * 0.00005 )) / 1.5) ));
         
                          
          cqi = LteAmc::GetCqiFromSpectralEfficiency (s);
          if (cqi == 0)
            {
              continue; // CQI == 0 means "out of range" (see table 7.2.3-1 of 36.213)
            }
          uldci.m_mcs = LteAmc::GetMcsFromCqi (cqi);
          //NS_LOG_DEBUG (this << " UE " <<  (*it).first << " minsinr " << minSinr << " -> mcs " << (uint16_t)uldci.m_mcs);
        	
        }
      uldci.m_tbSize = (LteAmc::GetTbSizeFromMcs (uldci.m_mcs, rbPerFlow) / 8); // MCS 0 -> UL-AMC TBD
//       NS_LOG_DEBUG (this << " UE " << (*it).first << " startPRB " << (uint32_t)uldci.m_rbStart << " nPRB " << (uint32_t)uldci.m_rbLen << " CQI " << cqi << " MCS " << (uint32_t)uldci.m_mcs << " TBsize " << uldci.m_tbSize);
      uldci.m_ndi = 1;
      uldci.m_cceIndex = 0;
      uldci.m_aggrLevel = 1;
      uldci.m_ueTxAntennaSelection = 3; // antenna selection OFF
      uldci.m_hopping = false;
      uldci.m_n2Dmrs = 0;
      uldci.m_tpc = 0; // no power control
      uldci.m_cqiRequest = false; // only period CQI at this stage
      uldci.m_ulIndex = 0; // TDD parameter
      uldci.m_dai = 1; // TDD parameter
      uldci.m_freqHopping = 0;
      uldci.m_pdcchPowerOffset = 0; // not used
      ret.m_dciList.push_back (uldci);
      it++;
      if (it==m_ceBsrRxed.end ())
        {
          // restart from the first
          it = m_ceBsrRxed.begin ();
        }
      if (rbAllocated == m_cschedCellConfig.m_ulBandwidth)
        {
          // Stop allocation: no more PRBs
          m_nextRntiUl = (*it).first;
          NS_LOG_DEBUG (this << " Next will be " << m_nextRntiUl);
          break;
        }
    } while ((*it).first != m_nextRntiUl);
  m_allocationMaps.insert (std::pair <uint16_t, std::vector <uint16_t> > (params.m_sfnSf, rbgAllocationMap));
  m_schedSapUser->SchedUlConfigInd (ret);
  return;
}

void
RrFfMacScheduler::DoSchedUlNoiseInterferenceReq (const struct FfMacSchedSapProvider::SchedUlNoiseInterferenceReqParameters& params)
{
  NS_LOG_FUNCTION (this);
  // TODO: Implementation of the API
  return;
}

void
RrFfMacScheduler::DoSchedUlSrInfoReq (const struct FfMacSchedSapProvider::SchedUlSrInfoReqParameters& params)
{
  NS_LOG_FUNCTION (this);
  // TODO: Implementation of the API
  return;
}

void
RrFfMacScheduler::DoSchedUlMacCtrlInfoReq (const struct FfMacSchedSapProvider::SchedUlMacCtrlInfoReqParameters& params)
{
  NS_LOG_FUNCTION (this);
  
  std::map <uint16_t,uint8_t>::iterator it;
  
  for (unsigned int i = 0; i < params.m_macCeList.size (); i++)
  {
    if ( params.m_macCeList.at (i).m_macCeType == MacCeListElement_s::BSR )
    {
      // buffer status report
      uint16_t rnti = params.m_macCeList.at (i).m_rnti;
      it = m_ceBsrRxed.find(rnti);
      if (it==m_ceBsrRxed.end())
      {
        // create the new entry
        uint8_t bsr = params.m_macCeList.at (i).m_macCeValue.m_bufferStatus.at (0);
        m_ceBsrRxed.insert( std::pair<uint16_t, uint8_t > (rnti, bsr)); // only 1 buffer status is working now
      }
      else
      {
        // update the CQI value
        (*it).second = params.m_macCeList.at (i).m_macCeValue.m_bufferStatus.at (0);
      }
    }
  }
  
  return;
}

void
RrFfMacScheduler::DoSchedUlCqiInfoReq (const struct FfMacSchedSapProvider::SchedUlCqiInfoReqParameters& params)
{
  NS_LOG_FUNCTION (this);
  //NS_LOG_DEBUG (this << " RX UL CQI at " << params.m_sfnSf);
  // correlate info on UL-CQIs with previous scheduling -> calculate m_sfnSf of transmission
  uint32_t frameNo = (0xFF & params.m_sfnSf) >> 4;
  uint32_t subframeNo = (0xF & params.m_sfnSf);
  //NS_LOG_DEBUG (this << " sfn " << frameNo << " sbfn " << subframeNo);
  if (subframeNo - m_schedTtiDelay < 0)
  {
  	frameNo--;
  }
  subframeNo = (subframeNo - m_schedTtiDelay) % 10;
  //NS_LOG_DEBUG (this << " Actual sfn " << frameNo << " sbfn " << subframeNo);
  uint16_t sfnSf = ((0xFF & frameNo) << 4) | (0xF & subframeNo);
  // retrieve the allocation for this subframe
  std::map <uint16_t, std::vector <uint16_t> >::iterator itMap;
  std::map <uint16_t, std::vector <double> >::iterator itCqi;
  itMap = m_allocationMaps.find (sfnSf);
  if (itMap == m_allocationMaps.end())
  {
  	NS_LOG_DEBUG (this << " Does not find info on allocation");
  	return;
  }
  for (uint32_t i = 0; i < (*itMap).second.size (); i++)
    {
  	  // convert from fixed point notation Sxxxxxxxxxxx.xxx to double    	
    	double sinr = LteFfConverter::fpS11dot3toDouble (params.m_ulCqi.m_sinr.at (i));
  	  //NS_LOG_DEBUG (this << " UE " << (*itMap).second.at (i) << " SINRfp " << params.m_ulCqi.m_sinr.at (i) << " sinrdb " << sinr);
  	  itCqi = m_ueCqi.find ((*itMap).second.at (i));
  	  if (itCqi == m_ueCqi.end ())
  	    {
  	    	// create a new entry
  	    	std::vector <double> newCqi;
  	    	for (uint32_t j = 0; j < m_cschedCellConfig.m_ulBandwidth; j++)
  	    	  {
  	    	  	if (i==j)
		 	    	  	{
		 	    	  		newCqi.push_back (sinr);
		 	    	  	}
  	    	  	else
  	    	  	  {
  	    	  	  	// initialize with maximum value according to the fixed point notation
  	    	  	  	newCqi.push_back (30.0);
  	    	  	  }
  	    	  	
  	    	  }
  	    	m_ueCqi.insert (std::pair <uint16_t, std::vector <double> > ((*itMap).second.at (i), newCqi));
  	    }
  	  else
  	    {
  	      // update the value
  	      (*itCqi).second.at (i) = sinr;
  	    }
  	  
  	}
  // remove obsolete info on allocation
  m_allocationMaps.erase (m_allocationMaps.begin (), ++itMap);

  return;
}

}