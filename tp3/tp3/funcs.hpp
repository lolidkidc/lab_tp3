#pragma once
#include "figure.hpp"
#include "rectangle.hpp"
#include "Circle.hpp"
#include "triangle.hpp"
#include "trapezoid.hpp"

void showall(Figure**& arr, int cnt);
void add(Figure**& arr, int cnt, float a, float b);
void add(Figure**& arr, int cnt, float r);
void addtr(Figure**& arr, int cnt, float a, float b);
void add(Figure**& arr, int cnt, float a, float b, float h);
void del(Figure**& arr, int cnt, int id);
void swap(Figure**& arr, int cnt, int id);
