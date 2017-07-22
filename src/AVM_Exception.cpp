/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVM_Exception.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbamping <kbamping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 12:07:24 by kbamping          #+#    #+#             */
/*   Updated: 2017/07/22 15:42:11 by kbamping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AVM_Exception.hpp"

AVM_Exception::AVM_Exception(const char *error) throw() :  _errorMsg(error) {

}

AVM_Exception::~AVM_Exception() throw() {

}

AVM_Exception::AVM_Exception(AVM_Exception const & src)
{
    if (this != &src)
        *this = src;
}

AVM_Exception & AVM_Exception::operator=(AVM_Exception const & rhs)
{
    this->_errorMsg = rhs._errorMsg;
    return (*this);
}

const char * AVM_Exception::what() const throw() {
    return (this->_errorMsg);
}
