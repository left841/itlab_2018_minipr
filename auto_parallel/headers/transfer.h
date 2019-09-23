#ifndef __TRANSFER_H__
#define __TRANSFER_H__

#include <queue>
#include <climits>
#include "mpi.h"

namespace auto_parallel
{

    class sender
    {
    private:

        MPI_Comm comm;
        int proc;
        int tag;
        std::queue<MPI_Request>* q;

    public:

        sender(MPI_Comm _comm, int _proc, std::queue<MPI_Request>* _q);

        void send(void* buf, int size, MPI_Datatype type);
        void isend(void* buf, int size, MPI_Datatype type);
        void big_send(void* buf, size_t size, MPI_Datatype type);
        void big_isend(void* buf, size_t size, MPI_Datatype type);

    };

    class receiver
    {
    private:

        MPI_Comm comm;
        int proc;
        int tag;
        std::queue<MPI_Request>* q;

    public:

        receiver(MPI_Comm _comm, int _proc, std::queue<MPI_Request>* _q);

        void recv(void* buf, int size, MPI_Datatype type);
        void irecv(void* buf, int size, MPI_Datatype type);
        void big_recv(void* buf, size_t size, MPI_Datatype type);
        void big_irecv(void* buf, size_t size, MPI_Datatype type);

    };

}

#endif // __TRANSFER_H__
