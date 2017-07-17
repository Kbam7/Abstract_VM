/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avm.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbam7 <kbam7@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 16:54:03 by kbam7             #+#    #+#             */
/*   Updated: 2017/07/15 22:02:16 by kbam7            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVM_HPP
# define AVM_HPP

#include <cstdio> // File I/O
#include <iostream>
#include <string>
#include <cstring>

//#include "IOperandFactory.hpp"

typedef struct  s_instruction
{
    std::string command;
    std::string operandType;
    std::string value;
}               t_instruction;

#endif /* AVM_HPP */