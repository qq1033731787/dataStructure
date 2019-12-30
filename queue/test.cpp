//
// Created by lzk on 2019-12-16.
//

#include <iostream>
#include "queue.h"

int main(){
    auto sq = new(stackQueue<int>);
    sq->enQueue(1);

    int tmp;
    sq->getFront(tmp);
    std::cout<< "aq front" << " " << tmp << std::endl;

    sq->deQueue(tmp);
    std::cout<< "aq dequeue" << " " << tmp << std::endl;

    sq->enQueue(2);
    sq->enQueue(3);
    sq->getFront(tmp);
    std::cout<< "aq front" << " " << tmp << std::endl;
    sq->deQueue(tmp);
    std::cout<< "aq dequeue" << " " << tmp << std::endl;
    sq->deQueue(tmp);
    std::cout<< "aq dequeue" << " " << tmp << std::endl;
//    auto aq = new(arrQueue<int>);
//    aq->enQueue(1);
//    aq->enQueue(2);
//    aq->enQueue(3);
//    aq->enQueueFromHead(100);
//    int tmp;
//    aq->getFront(tmp);
//    std::cout<< "aq front" << " " << tmp << std::endl;
//
//    aq->deQueueFromTail(tmp);
//    std::cout<< "de from tail" << " " << tmp << std::endl;
//
//    aq->deQueue(tmp);
//    std::cout<< "aq dequeue" << " " << tmp << std::endl;
//    aq->deQueue(tmp);
//    std::cout<< "aq dequeue" << " " << tmp << std::endl;
//    aq->deQueue(tmp);
//    std::cout<< "aq dequeue" << " " << tmp << std::endl;
//
//    auto lq = new(linkQueue<int>);
//    lq->enQueue(10);
//    lq->enQueue(20);
//    lq->enQueue(30);
//    lq->getFront(tmp);
//    std::cout<< "aq dequeue" << " " << tmp << std::endl;
//    lq->deQueue(tmp);
//    std::cout<< "aq dequeue" << " " << tmp << std::endl;
//    lq->deQueue(tmp);
//    std::cout<< "aq dequeue" << " " << tmp << std::endl;
//    lq->deQueue(tmp);
//    std::cout<< "aq dequeue" << " " << tmp << std::endl;
}
