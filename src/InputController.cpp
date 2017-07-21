/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InputController.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbam7 <kbam7@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 22:53:27 by kbam7             #+#    #+#             */
/*   Updated: 2017/07/20 15:20:52 by kbam7            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InputController.hpp"

InputController::InputController(std::list<t_instruction> & instruction_list)
{
    this->instruction_list = instruction_list;
}

InputController::~InputController(void)
{

}

InputController::InputController(InputController const & src)
{
    *this = src;
}

InputController & InputController::operator=(InputController const & rhs)
{
    this->inputFile = rhs.inputFile;

    return (*this);
}

int             InputController::getInputFileDescriptor(char *filepath)
{
    char    buf[maxStrSize];

    // open file
    if (!(this->inputFile = fopen(filepath, "r"))) {
        std::cout << C_BOLD << C_RED << "ERROR: " << C_NONE << C_BOLD << "Unable to open file! 'filepath'\n" << C_NONE
                << "Would you like to get input from the keyboard instead? [y/n]" << std::endl;
        std::cin >> buf;
        while (*buf)
        {
            if (*buf == 'y' || *buf == 'Y' || *buf == '\n')
            {
                std::cout << "Read from keyboard" << std::endl; // debug
                this->inputFile = stdin;
                return (EXIT_SUCCESS);
            } else if (*buf == 'n' || *buf == 'N') {
                std::cout << "Dont Read from keyboard" << std::endl; // debug
                return (EXIT_FAILURE);
            }
            else
                std::cin >> buf;
        }
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

int             InputController::readFromStdin(void)
{
    int                 n_line;
    std::list<char *>   tmp_list;
    char                *buf;
    std::regex           matchEndInput("( |\\t)*(;;)+( |\\t|\\n)*");
    
    buf = new char [this->maxStrSize];
    while (fgets(buf, maxStrSize, this->inputFile))
    {
        if (std::regex_match (buf, matchEndInput))
            break;
        // Add new instruction
        tmp_list.push_back(buf);

        buf = NULL;
        delete buf;
        buf = new char [this->maxStrSize];
    }

    n_line = 0;
    while (!tmp_list.empty())
    {
        n_line++;
        strcpy(buf, tmp_list.front());
        tmp_list.pop_front();

        // Comment or empty line
        if (*buf == ';' || *buf == '\n')
            continue;
       
        // Add new instruction
        this->instruction_list.push_back( parser(buf, n_line) );
    }
    delete buf;
    return (EXIT_SUCCESS);
}

int             InputController::readFromFile(void)
{
    char    buf[this->maxStrSize];
    int     n_line;

    // Read from file and return (std::string str)list of instructions
    n_line = 0;
    while (fgets(buf, maxStrSize, this->inputFile))
    {
        n_line++;
        // Comment or empty line
        if (*buf == ';' || *buf == '\n')
            continue;
            
        // Add new instruction
        this->instruction_list.push_back( parser(buf, n_line) );
    }
    fclose(this->inputFile);
    return (EXIT_SUCCESS);
}

char            *InputController::tokenize_line(char *line)
{
    static int  i = 0;
    static char *_line = NULL;
    int         token_len;
    char        *token;

/*    if (line == NULL) // debug
        std::cout << "--[tokenize_input]-- line: NULL  Using current '_line'  _line: \"" << _line << "\"  i: " << i <<  std::endl; // debug*/

    if (line != NULL)
    {
        _line = line;
        i = 0;
/*        std::cout << "--[tokenize_input]-- line: \"" << line << "\"  i: " << i << std::endl; // debug*/
    }
    token_len = 0;
    token = NULL;

    while (_line[i])
    {
        if (token_len < 1 && (_line[i] == ' ' || _line[i] == '\n' || _line[i] == '\t')) // whitespace before token
            while (_line[i] && (_line[i] == ' ' || _line[i] == '\n' || _line[i] == '\t'))
                ++i;
        else if (token_len > 0 && (_line[i] == ' ' || _line[i] == '\n' || _line[i] == '\t'))// whitespace/newline after token. 
            return (strndup(_line + (i - token_len), token_len));

        if (!_line[i]) // is there something left to analyze?
            return (NULL);
        
        if (_line[i] == ';') // start of comment
        {
            if (token_len > 0) // was reading a token until now
                token = strndup(_line + (i - token_len), token_len);
                
            i = strlen(_line); // increment i to end of string
            return (token);
        }

        if (_line[i] > 31 && _line[i] < 127) // printable character
            ++token_len;
        ++i;
    }
    if (token_len > 0)
        token = strndup(_line + (i - token_len), token_len);
    return (token);
}

t_command       InputController::get_command(char *cmd)
{
    if (strcmp(cmd, "push") == 0)
        return (CMD_PUSH);
    if (strcmp(cmd, "pop") == 0)
        return (CMD_POP);
    if (strcmp(cmd, "dump") == 0)
        return (CMD_DUMP);
    if (strcmp(cmd, "assert") == 0)
        return (CMD_ASSERT);
    if (strcmp(cmd, "add") == 0)
        return (CMD_ADD);
    if (strcmp(cmd, "sub") == 0)
        return (CMD_SUB);
    if (strcmp(cmd, "mul") == 0)
        return (CMD_MUL);
    if (strcmp(cmd, "div") == 0)
        return (CMD_DIV);
    if (strcmp(cmd, "mod") == 0)
        return (CMD_MOD);
    if (strcmp(cmd, "print") == 0)
        return (CMD_PRINT);
    if (strcmp(cmd, "exit") == 0)
        return (CMD_EXIT);
    return (CMD_NONE);
}

eOperandType    InputController::get_operandType(std::string str)
{
    if (strcmp(str.c_str(), "int8") == 0)
        return (AVM_INT8);
    if (strcmp(str.c_str(), "int16") == 0)
        return (AVM_INT16);
    if (strcmp(str.c_str(), "int32") == 0)
        return (AVM_INT32);
    if (strcmp(str.c_str(), "float") == 0)
        return (AVM_FLOAT);
    if (strcmp(str.c_str(), "double") == 0)
        return (AVM_DOUBLE);
    return (AVM_NONE);
}

t_instruction   InputController::parser(char *line, int n_line)
{
    t_instruction   currInstruction;
    char            *token;

/*    std::cout << "---" << line << "--- "; // debug*/

    // Init currInstruction
    currInstruction.valid = true;
    currInstruction.line = line;
    currInstruction.line_nr = n_line;
    currInstruction.command = CMD_NONE;
    currInstruction.operandType = AVM_NONE;
    currInstruction.value = "";

    // tokenize line
    token = tokenize_line(line);
    while (token)
    {
/*        std::cout << ">" << token << "< "; // debug*/

        try {
            parse_token(token, &currInstruction);
        }
        catch (std::exception & e)
        {
            std::cerr << C_BOLD << C_RED << "ERROR: " << C_NONE << C_BOLD << "Line: " << n_line << " --> "
                << e.what() << C_NONE << " '" << token << "'" << std::endl;
        }

        free(token);
        token = this->tokenize_line(NULL);
    }
/*    std::cout << "Line parsed.\n" << std::endl; // debug*/

    // Check instruction
    if (currInstruction.command == CMD_PUSH || currInstruction.command == CMD_ASSERT)
        if (!(currInstruction.operandType || currInstruction.value.length()))
            currInstruction.valid = false;

    return (currInstruction);
}

void        InputController::parse_token(char *token, t_instruction *currInstruction)
{
    std::regex      avm_commands("(push|pop|dump|assert|add|sub|mul|div|mod|print|exit)");
    std::regex      avm_dataTypes("(int8|int16|int32|float|double)\\(((\\+|-)?[0-9]+((.)*([0-9]+))?)\\)");
    std::cmatch     matches;

    if (std::regex_match (token, avm_commands))
    {
/*        std::cout << "Its a command\n"; // debug*/
        currInstruction->command = get_command(token);
    }
    else if (std::regex_match (token, avm_dataTypes))
    {
/*        std::cout << "Its a dataType\n";  // debug*/
        std::regex_match (token, matches, avm_dataTypes);

/*        std::cout << "-- The matches were: ";  // debug
        for (unsigned i=0; i < matches.size(); ++i) { // debug
            std::cout << "[" << matches[i] << "] "; // debug
        }*/

        // get data type and value from token
        currInstruction->operandType = this->get_operandType(matches[1]);
        currInstruction->value = matches[2];

        //      INTS
        //-- CHECK for overflow of SCHAR_MIN, SCHAR_MAX, SHRT_MIN, SHRT_MAX, LONG_MIN, LONG_MAX ----- #include <climits>
        // int8 max == 127
        // int16 max == 32767
        // int32 max == 2147483647

        //      FLOATING POINT
        // -- CHECK for overflow of FLT_MIN, FLT_MAX, DBL_MIN, DBL_MAX  ----- #include <cfloat>

    }
    else {
        // unrecognised token
        currInstruction->valid = false;
        throw (InputController::UnrecognisedToken());
    }
}

const char* InputController::UnrecognisedToken::what() const throw()
{
    return ("Found an unrecognised token :");
}

const char* InputController::InputFileError::what() const throw()
{
    return ("An error occurred with the input file :");
}

