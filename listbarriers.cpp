#include "listbarriers.h"

ListBarriers::ListBarriers()
{

}

ListBarriers::~ListBarriers()
{
    qDeleteAll(Paredes);
    qDeleteAll(Food);
}

void ListBarriers::BarriersMap()
{
    Paredes.push_back(new Barriers(12, 42, 224, 7, 0));
    Paredes.push_back(new Barriers(12, 286, 224, 4, 0));
    //lateral derecho
    Paredes.push_back(new Barriers(11, 42, 6, 109, 0));
    Paredes.push_back(new Barriers(11, 165, 6, 123, 0));
    //lateral izquierdo
    Paredes.push_back(new Barriers(232, 42, 4, 109, 0));
    Paredes.push_back(new Barriers(232, 165, 4, 123, 0));
    //portales
//    Paredes.push_back(new Barriers(-25, 149, 4, 19, 0));
//    Paredes.push_back(new Barriers(269, 149, 4, 19, 0));

    Paredes.push_back(new Barriers(31, 62, 26, 19, 0));
    Paredes.push_back(new Barriers(71, 62, 34, 19, 0));
    Paredes.push_back(new Barriers(143, 62, 34, 19, 0));
    Paredes.push_back(new Barriers(191, 62, 26, 19, 0));
    //---
    Paredes.push_back(new Barriers(-25, 118, 82, 34, 0));
    Paredes.push_back(new Barriers(191, 118, 82, 34, 0));
    Paredes.push_back(new Barriers(-25, 165, 82, 35, 0));
    Paredes.push_back(new Barriers(191, 165, 82, 35, 0));

    Paredes.push_back(new Barriers(95, 142, 58, 3, 0));
    Paredes.push_back(new Barriers(95, 173, 58, 3, 0));
    Paredes.push_back(new Barriers(95, 142, 3, 31, 0));
    Paredes.push_back(new Barriers(150, 142, 3, 31, 0));
    Paredes.push_back(new Barriers(31, 94, 26, 11, 0));
    Paredes.push_back(new Barriers(95, 94, 58, 11, 0));
    Paredes.push_back(new Barriers(191, 94, 25, 11, 0));
    Paredes.push_back(new Barriers(31, 213, 26, 12, 0));
    Paredes.push_back(new Barriers(71, 213, 34, 12, 0));
    Paredes.push_back(new Barriers(143, 213, 34, 12, 0));
    Paredes.push_back(new Barriers(191, 213, 26, 12, 0));
    Paredes.push_back(new Barriers(15, 238, 18, 10, 0));
    Paredes.push_back(new Barriers(215, 238, 18, 10, 0));
    Paredes.push_back(new Barriers(95, 238, 58, 10, 0));
    Paredes.push_back(new Barriers(71, 238, 10, 23, 0));
    Paredes.push_back(new Barriers(167, 238, 10, 23, 0));
    Paredes.push_back(new Barriers(31, 261, 74, 12, 0));
    Paredes.push_back(new Barriers(143, 261, 74, 12, 0));
    Paredes.push_back(new Barriers(95, 190, 58, 10, 0));
    Paredes.push_back(new Barriers(78, 118, 26, 10, 0));
    Paredes.push_back(new Barriers(143, 118, 26, 10, 0));
    Paredes.push_back(new Barriers(119, 47, 10, 32, 0));
    //laterales verticales
    Paredes.push_back(new Barriers(71, 94, 10, 58, 0));
    Paredes.push_back(new Barriers(167, 94, 10, 58, 0));
    Paredes.push_back(new Barriers(71, 165, 10, 35, 0));
    Paredes.push_back(new Barriers(167, 165, 10, 35, 0));
    //mitad vertical
    Paredes.push_back(new Barriers(119, 103, 10, 25, 0));
    Paredes.push_back(new Barriers(119, 199, 10, 26, 0));
    Paredes.push_back(new Barriers(119, 248, 10, 25, 0));
    Paredes.push_back(new Barriers(47, 223, 10, 25, 0));
    Paredes.push_back(new Barriers(191, 223, 10, 25, 0));
}

void ListBarriers::FoodsMap()
{
    //1ra vertival
    Food.push_back(new Barriers(1000, 1000, 3, 3, 1));
    Food.push_back(new Barriers(23, 53, 3, 3, 1));//1ra horizontal
    Food.push_back(new Barriers(23, 61, 3, 3, 1));
    Food.push_back(new Barriers(23, 77, 3, 3, 1));
    Food.push_back(new Barriers(23, 85, 3, 3, 1));
    Food.push_back(new Barriers(23, 93, 3, 3, 1));
    Food.push_back(new Barriers(23, 101, 3, 3, 1));
    Food.push_back(new Barriers(23, 109, 3, 3, 1));//2da horizontal
    Food.push_back(new Barriers(23, 206, 3, 3, 1));//3ra horizontal
    Food.push_back(new Barriers(23, 214, 3, 3, 1));
    Food.push_back(new Barriers(23, 222, 3, 3, 1));
    //4ta horizontal
    Food.push_back(new Barriers(23, 252, 3, 3, 1));
    Food.push_back(new Barriers(23, 260, 3, 3, 1));
    Food.push_back(new Barriers(23, 268, 3, 3, 1));
    Food.push_back(new Barriers(23, 276, 3, 3, 1));//5ta horizontal
    //2da vertical
    Food.push_back(new Barriers(63, 61, 3, 3, 1));
    Food.push_back(new Barriers(63, 69, 3, 3, 1));
    Food.push_back(new Barriers(63, 77, 3, 3, 1));
    Food.push_back(new Barriers(63, 93, 3, 3, 1));
    Food.push_back(new Barriers(63, 101, 3, 3, 1));
    Food.push_back(new Barriers(63, 117, 3, 3, 1));
    Food.push_back(new Barriers(63, 125, 3, 3, 1));
    Food.push_back(new Barriers(63, 133, 3, 3, 1));
    Food.push_back(new Barriers(63, 141, 3, 3, 1));
    Food.push_back(new Barriers(63, 149, 3, 3, 1));
    Food.push_back(new Barriers(63, 101, 3, 3, 1));
    Food.push_back(new Barriers(63, 157, 3, 3, 1));
    Food.push_back(new Barriers(63, 165, 3, 3, 1));
    Food.push_back(new Barriers(63, 173, 3, 3, 1));
    Food.push_back(new Barriers(63, 181, 3, 3, 1));
    Food.push_back(new Barriers(63, 189, 3, 3, 1));
    Food.push_back(new Barriers(63, 197, 3, 3, 1));
    Food.push_back(new Barriers(63, 213, 3, 3, 1));
    Food.push_back(new Barriers(63, 221, 3, 3, 1));
    Food.push_back(new Barriers(63, 237, 3, 3, 1));
    Food.push_back(new Barriers(63, 245, 3, 3, 1));
    Food.push_back(new Barriers(63, 253, 3, 3, 1));

    //3ra vertical
    Food.push_back(new Barriers(111, 61, 3, 3, 1));
    Food.push_back(new Barriers(111, 69, 3, 3, 1));
    Food.push_back(new Barriers(111, 77, 3, 3, 1));
    Food.push_back(new Barriers(111, 213, 3, 3, 1));
    Food.push_back(new Barriers(111, 221, 3, 3, 1));
    Food.push_back(new Barriers(111, 261, 3, 3, 1));
    Food.push_back(new Barriers(111, 269, 3, 3, 1));
    //4ta vertical
    Food.push_back(new Barriers(135, 61, 3, 3, 1));
    Food.push_back(new Barriers(135, 69, 3, 3, 1));
    Food.push_back(new Barriers(135, 77, 3, 3, 1));
    Food.push_back(new Barriers(135, 213, 3, 3, 1));
    Food.push_back(new Barriers(135, 221, 3, 3, 1));
    Food.push_back(new Barriers(135, 261, 3, 3, 1));
    Food.push_back(new Barriers(135, 269, 3, 3, 1));
    //5ta vertical
    Food.push_back(new Barriers(183, 61, 3, 3, 1));
    Food.push_back(new Barriers(183, 69, 3, 3, 1));
    Food.push_back(new Barriers(183, 77, 3, 3, 1));
    Food.push_back(new Barriers(183, 93, 3, 3, 1));
    Food.push_back(new Barriers(183, 101, 3, 3, 1));
    Food.push_back(new Barriers(183, 117, 3, 3, 1));
    Food.push_back(new Barriers(183, 125, 3, 3, 1));
    Food.push_back(new Barriers(183, 133, 3, 3, 1));
    Food.push_back(new Barriers(183, 141, 3, 3, 1));
    Food.push_back(new Barriers(183, 149, 3, 3, 1));
    Food.push_back(new Barriers(183, 101, 3, 3, 1));
    Food.push_back(new Barriers(183, 157, 3, 3, 1));
    Food.push_back(new Barriers(183, 165, 3, 3, 1));
    Food.push_back(new Barriers(183, 173, 3, 3, 1));
    Food.push_back(new Barriers(183, 181, 3, 3, 1));
    Food.push_back(new Barriers(183, 189, 3, 3, 1));
    Food.push_back(new Barriers(183, 197, 3, 3, 1));
    Food.push_back(new Barriers(183, 213, 3, 3, 1));
    Food.push_back(new Barriers(183, 221, 3, 3, 1));
    Food.push_back(new Barriers(183, 237, 3, 3, 1));
    Food.push_back(new Barriers(183, 245, 3, 3, 1));
    Food.push_back(new Barriers(183, 253, 3, 3, 1));
    //6ta vertical
    Food.push_back(new Barriers(223, 53, 3, 3, 1));//1ra horizontal
    Food.push_back(new Barriers(223, 61, 3, 3, 1));
    Food.push_back(new Barriers(223, 77, 3, 3, 1));
    Food.push_back(new Barriers(223, 85, 3, 3, 1));
    Food.push_back(new Barriers(223, 93, 3, 3, 1));
    Food.push_back(new Barriers(223, 101, 3, 3, 1));
    Food.push_back(new Barriers(223, 109, 3, 3, 1));//2da horizontal
    Food.push_back(new Barriers(223, 206, 3, 3, 1));//3ra horizontal
    Food.push_back(new Barriers(223, 214, 3, 3, 1));
    Food.push_back(new Barriers(223, 222, 3, 3, 1));
    //4ta horizontal
    Food.push_back(new Barriers(223, 252, 3, 3, 1));
    Food.push_back(new Barriers(223, 260, 3, 3, 1));
    Food.push_back(new Barriers(223, 268, 3, 3, 1));
    Food.push_back(new Barriers(223, 276, 3, 3, 1));//5ta horizontal
    //primera horizontal
    Food.push_back(new Barriers(223, 53, 3, 3, 1));
    Food.push_back(new Barriers(215, 53, 3, 3, 1));
    Food.push_back(new Barriers(207, 53, 3, 3, 1));
    Food.push_back(new Barriers(199, 53, 3, 3, 1));
    Food.push_back(new Barriers(191, 53, 3, 3, 1));
    Food.push_back(new Barriers(183, 53, 3, 3, 1));
    Food.push_back(new Barriers(175, 53, 3, 3, 1));
    Food.push_back(new Barriers(167, 53, 3, 3, 1));
    Food.push_back(new Barriers(159, 53, 3, 3, 1));
    Food.push_back(new Barriers(151, 53, 3, 3, 1));
    Food.push_back(new Barriers(143, 53, 3, 3, 1));
    Food.push_back(new Barriers(135, 53, 3, 3, 1));
    Food.push_back(new Barriers(31, 53, 3, 3, 1));
    Food.push_back(new Barriers(39, 53, 3, 3, 1));
    Food.push_back(new Barriers(47, 53, 3, 3, 1));
    Food.push_back(new Barriers(55, 53, 3, 3, 1));
    Food.push_back(new Barriers(63, 53, 3, 3, 1));
    Food.push_back(new Barriers(71, 53, 3, 3, 1));
    Food.push_back(new Barriers(79, 53, 3, 3, 1));
    Food.push_back(new Barriers(87, 53, 3, 3, 1));
    Food.push_back(new Barriers(95, 53, 3, 3, 1));
    Food.push_back(new Barriers(103, 53, 3, 3, 1));
    Food.push_back(new Barriers(111, 53, 3, 3, 1));
    //1.5 horizontal
    Food.push_back(new Barriers(215, 85, 3, 3, 1));
    Food.push_back(new Barriers(207, 85, 3, 3, 1));
    Food.push_back(new Barriers(199, 85, 3, 3, 1));
    Food.push_back(new Barriers(191, 85, 3, 3, 1));
    Food.push_back(new Barriers(183, 85, 3, 3, 1));
    Food.push_back(new Barriers(175, 85, 3, 3, 1));
    Food.push_back(new Barriers(167, 85, 3, 3, 1));
    Food.push_back(new Barriers(159, 85, 3, 3, 1));
    Food.push_back(new Barriers(151, 85, 3, 3, 1));
    Food.push_back(new Barriers(143, 85, 3, 3, 1));
    Food.push_back(new Barriers(135, 85, 3, 3, 1));
    Food.push_back(new Barriers(127, 85, 3, 3, 1));
    Food.push_back(new Barriers(119, 85, 3, 3, 1));
    Food.push_back(new Barriers(111, 85, 3, 3, 1));
    Food.push_back(new Barriers(103, 85, 3, 3, 1));
    Food.push_back(new Barriers(95, 85, 3, 3, 1));
    Food.push_back(new Barriers(87, 85, 3, 3, 1));
    Food.push_back(new Barriers(79, 85, 3, 3, 1));
    Food.push_back(new Barriers(71, 85, 3, 3, 1));
    Food.push_back(new Barriers(63, 85, 3, 3, 1));
    Food.push_back(new Barriers(55, 85, 3, 3, 1));
    Food.push_back(new Barriers(47, 85, 3, 3, 1));
    Food.push_back(new Barriers(39, 85, 3, 3, 1));
    Food.push_back(new Barriers(31, 85, 3, 3, 1));
    //2ra horizontal
    Food.push_back(new Barriers(215, 109, 3, 3, 1));
    Food.push_back(new Barriers(207, 109, 3, 3, 1));
    Food.push_back(new Barriers(199, 109, 3, 3, 1));
    Food.push_back(new Barriers(191, 109, 3, 3, 1));
    Food.push_back(new Barriers(183, 109, 3, 3, 1));
    Food.push_back(new Barriers(159, 101, 3, 3, 1));
    Food.push_back(new Barriers(159, 93, 3, 3, 1));
    Food.push_back(new Barriers(159, 109, 3, 3, 1));
    Food.push_back(new Barriers(151, 109, 3, 3, 1));
    Food.push_back(new Barriers(143, 109, 3, 3, 1));
    Food.push_back(new Barriers(135, 109, 3, 3, 1));
    Food.push_back(new Barriers(111, 109, 3, 3, 1));
    Food.push_back(new Barriers(103, 109, 3, 3, 1));
    Food.push_back(new Barriers(95, 109, 3, 3, 1));
    Food.push_back(new Barriers(87, 109, 3, 3, 1));
    Food.push_back(new Barriers(87, 101, 3, 3, 1));
    Food.push_back(new Barriers(87, 93, 3, 3, 1));
    Food.push_back(new Barriers(63, 109, 3, 3, 1));
    Food.push_back(new Barriers(55, 109, 3, 3, 1));
    Food.push_back(new Barriers(47, 109, 3, 3, 1));
    Food.push_back(new Barriers(39, 109, 3, 3, 1));
    Food.push_back(new Barriers(31, 109, 3, 3, 1));

    //3.5 horizontal
    Food.push_back(new Barriers(215, 206, 3, 3, 1));
    Food.push_back(new Barriers(207, 206, 3, 3, 1));
    Food.push_back(new Barriers(199, 206, 3, 3, 1));
    Food.push_back(new Barriers(191, 206, 3, 3, 1));
    Food.push_back(new Barriers(183, 206, 3, 3, 1));
    Food.push_back(new Barriers(175, 206, 3, 3, 1));
    Food.push_back(new Barriers(167, 206, 3, 3, 1));
    Food.push_back(new Barriers(159, 206, 3, 3, 1));
    Food.push_back(new Barriers(151, 206, 3, 3, 1));
    Food.push_back(new Barriers(143, 206, 3, 3, 1));
    Food.push_back(new Barriers(135, 206, 3, 3, 1));
    Food.push_back(new Barriers(111, 206, 3, 3, 1));
    Food.push_back(new Barriers(103, 206, 3, 3, 1));
    Food.push_back(new Barriers(95, 206, 3, 3, 1));
    Food.push_back(new Barriers(87, 206, 3, 3, 1));
    Food.push_back(new Barriers(79, 206, 3, 3, 1));
    Food.push_back(new Barriers(71, 206, 3, 3, 1));
    Food.push_back(new Barriers(63, 206, 3, 3, 1));
    Food.push_back(new Barriers(55, 206, 3, 3, 1));
    Food.push_back(new Barriers(47, 206, 3, 3, 1));
    Food.push_back(new Barriers(39, 206, 3, 3, 1));
    Food.push_back(new Barriers(31, 206, 3, 3, 1));
    //5ta horizontal
    Food.push_back(new Barriers(223, 276, 3, 3, 1));
    Food.push_back(new Barriers(215, 276, 3, 3, 1));
    Food.push_back(new Barriers(207, 276, 3, 3, 1));
    Food.push_back(new Barriers(199, 276, 3, 3, 1));
    Food.push_back(new Barriers(191, 276, 3, 3, 1));
    Food.push_back(new Barriers(183, 276, 3, 3, 1));
    Food.push_back(new Barriers(175, 276, 3, 3, 1));
    Food.push_back(new Barriers(167, 276, 3, 3, 1));
    Food.push_back(new Barriers(159, 276, 3, 3, 1));
    Food.push_back(new Barriers(151, 276, 3, 3, 1));
    Food.push_back(new Barriers(143, 276, 3, 3, 1));
    Food.push_back(new Barriers(135, 276, 3, 3, 1));
    Food.push_back(new Barriers(23, 276, 3, 3, 1));
    Food.push_back(new Barriers(31, 276, 3, 3, 1));
    Food.push_back(new Barriers(39, 276, 3, 3, 1));
    Food.push_back(new Barriers(47, 276, 3, 3, 1));
    Food.push_back(new Barriers(55, 276, 3, 3, 1));
    Food.push_back(new Barriers(63, 276, 3, 3, 1));
    Food.push_back(new Barriers(71, 276, 3, 3, 1));
    Food.push_back(new Barriers(79, 276, 3, 3, 1));
    Food.push_back(new Barriers(87, 276, 3, 3, 1));
    Food.push_back(new Barriers(95, 276, 3, 3, 1));
    Food.push_back(new Barriers(103, 276, 3, 3, 1));
    Food.push_back(new Barriers(111, 276, 3, 3, 1));
    Food.push_back(new Barriers(126, 276, 3, 3, 1));
    Food.push_back(new Barriers(118, 276, 3, 3, 1));
    //4ta horizontal
    Food.push_back(new Barriers(215, 252, 3, 3, 1));
    Food.push_back(new Barriers(208, 252, 3, 3, 1));
    Food.push_back(new Barriers(201, 252, 3, 3, 1));
    Food.push_back(new Barriers(193, 252, 3, 3, 1));
    Food.push_back(new Barriers(158, 252, 3, 3, 1));
    Food.push_back(new Barriers(150, 252, 3, 3, 1));
    Food.push_back(new Barriers(143, 252, 3, 3, 1));
    Food.push_back(new Barriers(135, 252, 3, 3, 1));
    Food.push_back(new Barriers(159, 244, 3, 3, 1));
    Food.push_back(new Barriers(159, 236, 3, 3, 1));
    Food.push_back(new Barriers(207, 244, 3, 3, 1));
    Food.push_back(new Barriers(207, 236, 3, 3, 1));
    Food.push_back(new Barriers(31, 252, 3, 3, 1));
    Food.push_back(new Barriers(39, 252, 3, 3, 1));
    Food.push_back(new Barriers(47, 252, 3, 3, 1));
    Food.push_back(new Barriers(39, 244, 3, 3, 1));
    Food.push_back(new Barriers(39, 236, 3, 3, 1));
    Food.push_back(new Barriers(55, 252, 3, 3, 1));
    Food.push_back(new Barriers(103, 252, 3, 3, 1));
    Food.push_back(new Barriers(87, 244, 3, 3, 1));
    Food.push_back(new Barriers(87, 236, 3, 3, 1));
    Food.push_back(new Barriers(95, 252, 3, 3, 1));
    Food.push_back(new Barriers(87, 252, 3, 3, 1));
    Food.push_back(new Barriers(111, 252, 3, 3, 1));
    //3.5 horizontal
    Food.push_back(new Barriers(31, 230, 3, 3, 1));
    Food.push_back(new Barriers(39, 230, 3, 3, 1));
    Food.push_back(new Barriers(63, 230, 3, 3, 1));
    Food.push_back(new Barriers(71, 230, 3, 3, 1));
    Food.push_back(new Barriers(79, 230, 3, 3, 1));
    Food.push_back(new Barriers(87, 230, 3, 3, 1));
    Food.push_back(new Barriers(95, 230, 3, 3, 1));
    Food.push_back(new Barriers(103, 230, 3, 3, 1));
    Food.push_back(new Barriers(111, 230, 3, 3, 1));
//    Food.push_back(new Barriers(119, 230, 3, 3, 1));
//    Food.push_back(new Barriers(127, 230, 3, 3, 1));
    Food.push_back(new Barriers(135, 230, 3, 3, 1));
    Food.push_back(new Barriers(143, 230, 3, 3, 1));
    Food.push_back(new Barriers(151, 230, 3, 3, 1));
    Food.push_back(new Barriers(159, 230, 3, 3, 1));
    Food.push_back(new Barriers(167, 230, 3, 3, 1));
    Food.push_back(new Barriers(175, 230, 3, 3, 1));
    Food.push_back(new Barriers(183, 230, 3, 3, 1));
    Food.push_back(new Barriers(207, 230, 3, 3, 1));
    Food.push_back(new Barriers(215, 230, 3, 3, 1));

}

void ListBarriers::SpecialBarriers()
{

    Portals.push_back(new Barriers(-25, 149, 4, 19, 0));
    Portals.push_back(new Barriers(269, 149, 4, 19, 0));
    Portals.push_back(new Barriers(-13, 149, 24, 20, 2));
    Portals.push_back(new Barriers(237, 149, 24, 20, 2));

    Lifes.push_back(new Barriers(15, 292, 14, 13, 1));
    Lifes.push_back(new Barriers(30, 292, 14, 13, 1));
    Lifes.push_back(new Barriers(45, 292, 14, 13, 1));


}

void ListBarriers::CreateBarriers(int X, int Y, int WidthBarrier, int HeightBarrier, int Color)
{
    Paredes.push_back(new Barriers(X, Y, WidthBarrier, HeightBarrier, Color));
}

void ListBarriers::PowerUp()
{
    PowerUps.push_back(new Barriers(1000, 1100, 8, 8, 3));
    PowerUps.push_back(new Barriers(21, 66, 8, 8, 3));
    PowerUps.push_back(new Barriers(21, 228, 8, 8, 3));
    PowerUps.push_back(new Barriers(221, 66, 8, 8, 3));
    PowerUps.push_back(new Barriers(221, 228, 8, 8, 3));
}

