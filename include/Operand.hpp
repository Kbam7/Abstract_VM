/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbamping <kbamping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 19:39:33 by kbam7             #+#    #+#             */
/*   Updated: 2017/07/23 15:47:28 by kbamping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_INT8_HPP
# define OPERAND_INT8_HPP

#include <iostream>
# include "IOperand.hpp"
# include "AVM_Exception.hpp"
# include <climits>
# include <cfloat>

template <typename T>
class Operand : public IOperand
{
    public:
        Operand(eOperandType type, double value)
        {
            switch (type)
            {
                case AVM_INT8:
                    if (value >= SCHAR_MIN)
                        if (value <= SCHAR_MAX)
                        {
                            this->_precision = 0;
                            break;
                        }
                        else
                            throw AVM_Exception::AVM_Exception("Int8 Overflow");
                    else
                        throw AVM_Exception::AVM_Exception("Int8 Underflow");
                case AVM_INT16:
                    if (value >= SHRT_MIN)
                        if (value <= SHRT_MAX)
                        {
                            this->_precision = 1;
                            break;
                        }
                        else
                            throw AVM_Exception::AVM_Exception("Int16 Overflow");
                    else
                        throw AVM_Exception::AVM_Exception("Int16 Underflow");
                case AVM_INT32:
                    if (value >= INT_MIN)
                        if (value <= INT_MAX)
                        {
                            this->_precision = 2;
                            break;
                        }
                        else
                            throw AVM_Exception::AVM_Exception("Int32 Overflow");
                    else
                        throw AVM_Exception::AVM_Exception("Int32 Underflow");
                case AVM_FLOAT:
                    if (value >= -FLT_MAX)
                        if (value <= FLT_MAX)
                        {
                            this->_precision = 3;
                            break;
                        }
                        else
                            throw AVM_Exception::AVM_Exception("Float Overflow");
                    else
                        throw AVM_Exception::AVM_Exception("Float Underflow");
                case AVM_DOUBLE:
                    if (value >= -DBL_MAX)
                        if (value <= DBL_MAX)
                        {
                            this->_precision = 4;
                            break;
                        }
                        else
                            throw AVM_Exception::AVM_Exception("Double Overflow");
                    else
                        throw AVM_Exception::AVM_Exception("Double Underflow");
                default:
                    break;
            }
            this->_type = type;
            this->_value = value;
            this->_string = std::to_string(this->_value);
        };

        ~Operand()
        {

        };

        Operand(const Operand & src)
        {
            if (this != &src)
                *this = src;
        };

        Operand & operator=(const Operand & rhs)
        {
            if (this != &rhs)
            {
                this->_value = rhs._value;
                this->_string = rhs._string;
                this->_type = rhs._type;
                this->_precision = rhs._precision;
            }
            return (*this);
        };

        virtual int             getPrecision(void) const
        {
            return (this->_precision);
        };

        virtual eOperandType    getType(void) const
        {
            return (this->_type);
        };
        
        virtual std::string const & toString( void ) const
        {
            return (this->_string);
        };

        virtual IOperand const * operator+( IOperand const & rhs ) const
        {
            eOperandType prec;

            prec = (this->_precision >= rhs.getPrecision()) ? this->_type : rhs.getType();
            switch (prec)
            {
                case AVM_INT8:
                    return (new Operand<char>(prec, this->_value + stod(rhs.toString())));
                case AVM_INT16:
                    return (new Operand<short>(prec, this->_value + stod(rhs.toString())));
                case AVM_INT32:
                    return (new Operand<int>(prec, this->_value + stod(rhs.toString())));
                case AVM_FLOAT:
                    return (new Operand<float>(prec, this->_value + stod(rhs.toString())));
                case AVM_DOUBLE:
                    return (new Operand<double>(prec, this->_value + stod(rhs.toString())));
            }
        };

        virtual IOperand const * operator-( IOperand const & rhs ) const
        {
            eOperandType prec;

            prec = (this->_precision >= rhs.getPrecision()) ? this->_type : rhs.getType();
            switch (prec)
            {
                case AVM_INT8:
                    return (new Operand<char>(prec, this->_value - stod(rhs.toString())));
                case AVM_INT16:
                    return (new Operand<short>(prec, this->_value - stod(rhs.toString())));
                case AVM_INT32:
                    return (new Operand<int>(prec, this->_value - stod(rhs.toString())));
                case AVM_FLOAT:
                    return (new Operand<float>(prec, this->_value - stod(rhs.toString())));
                case AVM_DOUBLE:
                    return (new Operand<double>(prec, this->_value - stod(rhs.toString())));
            }
        };
        virtual IOperand const * operator*( IOperand const & rhs ) const
        {
            eOperandType prec;

            prec = (this->_precision >= rhs.getPrecision()) ? this->_type : rhs.getType();
            switch (prec)
            {
                case AVM_INT8:
                    return (new Operand<char>(prec, this->_value * stod(rhs.toString())));
                case AVM_INT16:
                    return (new Operand<short>(prec, this->_value * stod(rhs.toString())));
                case AVM_INT32:
                    return (new Operand<int>(prec, this->_value * stod(rhs.toString())));
                case AVM_FLOAT:
                    return (new Operand<float>(prec, this->_value * stod(rhs.toString())));
                case AVM_DOUBLE:
                    return (new Operand<double>(prec, this->_value * stod(rhs.toString())));
            }
        }

        virtual IOperand const * operator/( IOperand const & rhs ) const
        {
            eOperandType prec;
            
            if (this->_value == 0 || stod(rhs.toString()) == 0)
                throw AVM_Exception("Div failed - Cannot divide with zero");

            prec = (this->_precision >= rhs.getPrecision()) ? this->_type : rhs.getType();
            switch (prec)
            {
                case AVM_INT8:
                    return (new Operand<char>(prec, this->_value / stod(rhs.toString())));
                case AVM_INT16:
                    return (new Operand<short>(prec, this->_value / stod(rhs.toString())));
                case AVM_INT32:
                    return (new Operand<int>(prec, this->_value / stod(rhs.toString())));
                case AVM_FLOAT:
                    return (new Operand<float>(prec, this->_value / stod(rhs.toString())));
                case AVM_DOUBLE:
                    return (new Operand<double>(prec, this->_value / stod(rhs.toString())));
            }
        }

        virtual IOperand const * operator%( IOperand const & rhs ) const
        {
            eOperandType prec;
            
            if (this->_value == 0 || stod(rhs.toString()) == 0)
                throw AVM_Exception("Mod failed - Cannot modulus with zero");
            if (this->_type == AVM_FLOAT || rhs.getType() == AVM_FLOAT)
                throw AVM_Exception("Mod failed - Cannot modulus with float");
            if (this->_type == AVM_DOUBLE || rhs.getType() == AVM_DOUBLE)
                throw AVM_Exception("Mod failed - Cannot modulus with double");

            prec = (this->_precision >= rhs.getPrecision()) ? this->_type : rhs.getType();
            switch (prec)
            {
                case AVM_INT8:
                    return (new Operand<char>(prec, (int)this->_value % stoi(rhs.toString())));
                case AVM_INT16:
                    return (new Operand<short>(prec, (int)this->_value % stoi(rhs.toString())));
                case AVM_INT32:
                    return (new Operand<int>(prec, (int)this->_value % stoi(rhs.toString())));
                case AVM_FLOAT:
                    return (new Operand<float>(prec, (int)this->_value % stoi(rhs.toString())));
                case AVM_DOUBLE:
                    return (new Operand<double>(prec, (int)this->_value % stoi(rhs.toString())));
            }
        }

    private:
        T               _value;
        eOperandType    _type;
        int             _precision;
        std::string     _string;
};

#endif