/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand_Int8.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbam7 <kbam7@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 19:39:33 by kbam7             #+#    #+#             */
/*   Updated: 2017/07/10 20:06:55 by kbam7            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_INT8_HPP
# define OPERAND_INT8_HPP

# include "IOperand.hpp"

class Operand_Int8 : public IOperand
{
    public:
        virtual int             getPrecision(void) const;
        virtual eOperandType    getType(void) const;

        virtual IOperand const * operator+( IOperand const & rhs ) const;
        virtual IOperand const * operator-( IOperand const & rhs ) const;
        virtual IOperand const * operator*( IOperand const & rhs ) const;
        virtual IOperand const * operator/( IOperand const & rhs ) const;
        virtual IOperand const * operator%( IOperand const & rhs ) const;

        virtual std::string const & toString( void ) const;

    private:
        int8_t          _value;
        std::string     _string;
        eOperandType    _type;
}

#endif