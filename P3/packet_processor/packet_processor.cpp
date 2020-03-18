#include "packet_processor.hpp"

PacketProcessor::PacketProcessor(size_t size)
{
   //TODO
   max_buffer = size;
}

Response 
PacketProcessor::process(const Packet &packet)
{
    //TODO

//Cuando llega un paquete:
//
// 1. quitaremos de la cola todos los que llegaron antes y que
//    ya han sido procesados.
// 2. Si no hay espacio en la cola, este paquete será dropped y termina
//    su procesado retornando Response(true, 0).
// 3. Sino
// 3.1 Si la cola está vacía, el paquete será procesado inmediatamente
//     retornando Response(false, tiempo de llegada)
// 3.2 Sino será encolado y su tiempo de inicio de proceso será 
//     por lo tanto el tiempo finalización del procesado del
//     último paquete encolado retornando 
//     Response(false, tiempo de finalización del último paquete).
//
// Cuestión: En la cola, ¿qué encolamos?; el tiempo de llegada o 
// el tiempo de finalización.

    while(q.front() <= packet.arrival_time && !q.is_empty()){
        q.deque();
    }

    if (q.size() == max_buffer){
        return Response(true, 0);
    }
    else if (q.is_empty()){
        q.enque(packet.arrival_time + packet.process_time);
        return Response(false, packet.arrival_time);
    }
    else{
        int tiempo = q.back();
        q.enque(tiempo + packet.process_time);
        return Response(false, tiempo);
    }
    return Response(true, 0);
}


/** @brief process the packets and generate a response for each of them.*/
std::vector <Response>
process_packets(const std::vector <Packet> &packets,
                PacketProcessor& p)
{
    std::vector <Response> responses;
    for (size_t i = 0; i < packets.size(); ++i)
        responses.push_back(p.process(packets[i]));
    return responses;
}

/** @brief print the processing start times for the packets.*/
std::ostream&
write_responses(std::ostream &out, const std::vector <Response> &responses)
{
    for (size_t i = 0; i < responses.size(); ++i)
        out << (responses[i].dropped ? -1 : responses[i].start_time) << std::endl;
    return out;
}
