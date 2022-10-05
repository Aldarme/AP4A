/**
 * @author Muna Ayuni MAHATHIR
 * @file Server.hpp
 * @brief This class is used to collect data from class Sensor and send the data to the server.
 */

#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP


class Scheduler
{
    public:
        Scheduler();
        virtual ~Scheduler(){}
        void takedata() ;
     ;

    protected:

    private: bool m_activeC, m_activeF ;
};

#endif // SCHEDULER_HPP

