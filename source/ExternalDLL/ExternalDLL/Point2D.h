/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#pragma once
#include <iostream>

template<typename T> struct Point2D {
	T x;
	T y;

	Point2D():
		x(0), y(0){
	}
	
	Point2D(const T x, const T y):
		x(x), y(y){
	};

	void set(const T x, const T y){
		this->x = x;
		this->y = y;
	}
	void set(const Point2D &other){
		this->x = other.x;
		this->y = other.y;
	}

	void setX(const T x){
		this->x = x;
	}
	void setY(const T y){
		this->y = y;
	}

	T getX() const {
		return x;
	}

	T getY() const {
		return y;
	}

	//Unary
	Point2D operator+() const {
		return Point2D(+this->x, +this->y);
	}

	Point2D operator-() const {
		return Point2D(-this->x, -this->y);
	}

	//pre and post fix
	Point2D operator++(){
		this->x++;
		this->y++;
		return *this;
	}

	Point2D operator++(int){
		Point2D tmp(*this);
		operator++();
		return tmp;
	}

	Point2D operator--(){
		this->x--;
		this->y--;
		return *this;
	}

	Point2D operator--(int){
		Point2D tmp(*this);
		operator--();
		return tmp;
	}

	//Compare operators
	bool operator== (const Point2D &other) const {
		return (this->x == other.x && this->y == other.y);

	}

	bool operator!= (const Point2D &other) const{
		return (this->x != other.x || this->y != other.y);
	}

	//By Point2D
	Point2D operator+ (const Point2D &other) const {
		return Point2D(this->x + other.x, this->y + other.y);
	}

	Point2D operator- (const Point2D &other) const {
		return Point2D(this->x - other.x, this->y - other.y);
	}

	Point2D operator* (const Point2D &other) const{
		return Point2D(this->x * other.x, this->y * other.y);
	}

	Point2D operator/ (const Point2D &other) const{
		return Point2D(this->x / other.x, this->y / other.y);
	}

	Point2D operator% (const Point2D &other) const{
		return Point2D(this->x % other.x, this->y % other.y);
	}

	Point2D operator=(const Point2D &other){
		this->x = other.x;
		this->y = other.y;
		return *this;
	}

	Point2D operator+=(const Point2D &other){
		this->x += other.x;
		this->y += other.y;
		return *this;
	}

	Point2D operator-=(const Point2D &other){
		this->x -= other.x;
		this->y -= other.y;
		return *this;
	}

	Point2D operator*= (const Point2D &other){
		this->x *= other.x;
		this->y *= other.y;
		return *this;
	}

	Point2D operator/= (const Point2D &other){
		this->x /= other.x;
		this->y /= other.y;
		return *this;
	}

	Point2D operator%= (const Point2D &other){
		this->x %= other.x;
		this->y %= other.y;
		return *this;
	}

	//By type T
	Point2D operator+ (const T &other) const {
		return Point2D(this->x + other, this->y + other);
	}

	Point2D operator- (const T &other) const {
		return Point2D(this->x - other, this->y - other);
	}

	Point2D operator* (const T &other) const{
		return Point2D(this->x * other, this->y * other);
	}

	Point2D operator/ (const T &other) const{
		return Point2D(this->x / other, this->y / other);
	}

	Point2D operator% (const T &other) const{
		return Point2D(this->x % other, this->y % other);
	}

	Point2D operator=(const T &other){
		this->x = other;
		this->y = other;
		return *this;
	}

	Point2D operator+=(const T &other){
		this->x += other;
		this->y += other;
		return *this;
	}

	Point2D operator-=(const T &other){
		this->x -= other;
		this->y -= other;
		return *this;
	}

	Point2D operator*= (const T &other){
		this->x *= other;
		this->y *= other;
		return *this;
	}

	Point2D operator/= (const T &other){
		this->x /= other;
		this->y /= other;
		return *this;
	}

	Point2D operator%= (const T &other){
		this->x %= other;
		this->y %= other;
		return *this;
	}

	template<class T>
	friend std::ostream& operator<<(std::ostream& out, Point2D<T> &other);
};

template<typename T>
std::ostream& operator<< (std::ostream &out, Point2D<T> &other){
	std::cout << "(" << other.x << ", " << other.y << ")";
	return out;
}


typedef Point2D<int> IntPoint2D;
typedef Point2D<float> FloatPoint2D;
typedef Point2D<double> DoublePoint2D;