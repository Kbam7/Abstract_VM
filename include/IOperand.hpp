/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbam7 <kbam7@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 16:59:09 by kbam7             #+#    #+#             */
/*   Updated: 2017/07/18 11:11:57 by kbam7            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IOPERAND_HPP
# define IOPERAND_HPP

typedef enum    e_OperandType
{
    AVM_NONE = 0,
    AVM_INT8,
    AVM_INT16,
    AVM_INT32,
    AVM_FLOAT,
    AVM_DOUBLE
}              eOperandType;

class IOperand
{
    public:
        virtual int             getPrecision(void) const = 0;
        virtual eOperandType    getType(void) const = 0;

        virtual IOperand const * operator+( IOperand const & rhs ) const = 0;
        virtual IOperand const * operator-( IOperand const & rhs ) const = 0;
        virtual IOperand const * operator*( IOperand const & rhs ) const = 0;
        virtual IOperand const * operator/( IOperand const & rhs ) const = 0;
        virtual IOperand const * operator%( IOperand const & rhs ) const = 0;

        virtual std::string const & toString( void ) const = 0;

        virtual ~IOperand (void ) {}      
};

#endif /* IOPERAND_HPP */