/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:11:55 by ssuchane          #+#    #+#             */
/*   Updated: 2025/01/23 16:28:49 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) {}

Fixed::Fixed(const int intValue) {
    _fixedPointValue = intValue << _fractionalBits;
}

Fixed::Fixed(const float floatValue) {
    _fixedPointValue = roundf(floatValue * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &other) {
    *this = other;
}

Fixed::~Fixed() {}

Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other)
        _fixedPointValue = other.getRawBits();
    return *this;
}

int Fixed::getRawBits() const {
    return _fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    _fixedPointValue = raw;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return _fixedPointValue >> _fractionalBits;
}

bool Fixed::operator>(const Fixed &other) const {
    return _fixedPointValue > other._fixedPointValue;
}

bool Fixed::operator<(const Fixed &other) const {
    return _fixedPointValue < other._fixedPointValue;
}

bool Fixed::operator>=(const Fixed &other) const {
    return _fixedPointValue >= other._fixedPointValue;
}

bool Fixed::operator<=(const Fixed &other) const {
    return _fixedPointValue <= other._fixedPointValue;
}

bool Fixed::operator==(const Fixed &other) const {
    return _fixedPointValue == other._fixedPointValue;
}

bool Fixed::operator!=(const Fixed &other) const {
    return _fixedPointValue != other._fixedPointValue;
}

Fixed Fixed::operator+(const Fixed &other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
    return Fixed(this->toFloat() / other.toFloat());
}
