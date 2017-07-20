/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InputController.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbam7 <kbam7@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 22:21:33 by kbam7             #+#    #+#             */
/*   Updated: 2017/07/19 23:43:37 by kbam7            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_CONTROLLER_HPP
# define INPUT_CONTROLLER_HPP

class InputController
{
    public:
        InputController(void);
        ~InputController(void);
        InputController(InputController const & src);
        InputController & operator=(InputController const & rhs);

        const size_t    maxStrSize = 1024;
        FILE            *inputFile;

        int             getInputFileDescriptor(char *filepath);
        int             readFromStdin(void);
        int             readFromFile(void);
        char            *tokenize_line(char *line);
        t_command       get_command(char *cmd);
        eOperandType    get_operandType(std::string str);
        t_instruction   parser(char *line, int n_line);
        void            parse_token(char *token, t_instruction *currInstruction);

        class UnrecognisedToken: public std::exception {
            public:
                virtual const char* what() const throw();
        };

};

#endif /* INPUT_CONTROLLER_HPP */