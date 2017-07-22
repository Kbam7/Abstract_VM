/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbam7 <kbam7@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 19:39:33 by kbam7             #+#    #+#             */
/*   Updated: 2017/07/22 08:49:31 by kbam7            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_INT8_HPP
# define OPERAND_INT8_HPP

# include "IOperand.hpp"

template <typename T>
class Operand : public IOperand
{
    public:
        Operand::Operand(eOperandType type, std::string value)
        {
            switch (type)
            {
                case AVM_INT8:

                case AVM_INT16:
                case AVM_INT32:
                case AVM_FLOAT:
                case AVM_DOUBLE:
                default:
                    break;
            }
        }

        Operand::~Operand()
        {

        }

        Operand::Operand(const Operand & src)
        {
            if (this != &src)
                *this = src;
        }

        Operand & Operand::operator=(const Operand & rhs)
        {
            if (this != &rhs)
            {
                this->_value = rhs._value;
                this->_string = rhs._string;
                this->_type = rhs._type;
                this->_precision = rhs._precision;
            }
            return (*this);
        }

        virtual int             Operand::getPrecision(void) const
        {
            return (this->_precision);
        }

        virtual eOperandType    Operand::getType(void) const
        {
            return (this->_type);
        }
        
        virtual std::string const & Operand::toString( void ) const;

        virtual IOperand const * Operand::operator+( IOperand const & rhs ) const;
        virtual IOperand const * Operand::operator-( IOperand const & rhs ) const;
        virtual IOperand const * Operand::operator*( IOperand const & rhs ) const;
        virtual IOperand const * Operand::operator/( IOperand const & rhs ) const;
        virtual IOperand const * Operand::operator%( IOperand const & rhs ) const;

    private:
        T               _value;
        std::string     _string;
        eOperandType    _type;
        int             _precision;
};

#endif