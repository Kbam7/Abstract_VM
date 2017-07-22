/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbamping <kbamping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 18:40:21 by kbam7             #+#    #+#             */
/*   Updated: 2017/07/22 15:11:42 by kbamping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Abstract_VM.hpp"

int     main(int argc, char **argv)
{
    Abstract_VM     *avm;
    InputHandler *ic;
    char        *path;

    path = NULL;
    avm = new Abstract_VM();
    ic = avm->InputHandler;
    
    if (argc > 1)
    {
        if (ic->getInputFileDescriptor(argv[1]) ==  EXIT_FAILURE)
            return (EXIT_SUCCESS);
        ic->readFromFile();
    }
    else
        ic->readFromStdin();

    avm->run_instructions();

    return (0);
}