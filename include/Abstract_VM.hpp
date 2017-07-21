/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Abstract_VM.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbam7 <kbam7@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 16:54:03 by kbam7             #+#    #+#             */
/*   Updated: 2017/07/20 15:14:17 by kbam7            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACT_VM_HPP
# define ABSTRACT_VM_HPP

# include <cstdio> // File I/O
# include <iostream>
# include <string>
# include <cstring>
# include <regex>
# include <list>
# include <stack>
# include <exception>

# include "IOperandFactory.hpp"
# include "InputController.hpp"

class Abstract_VM
{
    public:
        Abstract_VM(void);
        ~Abstract_VM(void);
        Abstract_VM(Abstract_VM const & src);
        Abstract_VM & operator=(Abstract_VM const & rhs);

        int             run_instructions(void);

        InputController             *inputController;
        std::list<t_instruction>    instruction_list;
        std::stack<IOperand *>      avm_stack;


};

#endif /* ABSTRACT_VM_HPP */