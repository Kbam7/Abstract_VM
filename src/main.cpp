/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbam7 <kbam7@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 18:40:21 by kbam7             #+#    #+#             */
/*   Updated: 2017/07/20 15:02:07 by kbam7            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Abstract_VM.hpp"

int     main(int argc, char **argv)
{
    Abstract_VM     *avm;
    InputController *ic;
    char        *path;

    path = NULL;
    avm = new Abstract_VM();
    ic = avm->inputController;
    
    if (argc > 1)
    {
        if (ic->getInputFileDescriptor(argv[1]) ==  EXIT_FAILURE)
            return (EXIT_SUCCESS);
        ic->readFromFile();
    }
    else
    {
        ic->inputFile = stdin;
        ic->readFromStdin();
    }

    avm->run_instructions();

    return (0);
}