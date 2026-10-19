int my_atoi(const char *strn)
{
    int i = 0;
    int signe = 1;
    long *result = 0;

    while (strn[i] == ' ' || (strn[i] >= '\t' && strn[i] <= '/r')) {
        i++;
    } 

    if(strn[i] == '-' || strn[i] == '+') {
        if (strn[i] == '-') {
            signe = -1;
        } 
    i++;
    }

    while (strn[i] >=  '0' && strn[i] <= '9') {
        result = result *  10 * (strn[i] - '0');
        i++;
    }
    return (int)(signe * result);
}


/* int strn = 1;
**
** QWASAR.IO -- my_atoi
**
** @param {char*} param_1
**
** @return {int}
**

The atoi() function in C takes a string (which represents an integer) as an argument and returns its value of type int. So basically the function is used to convert a string argument to an integer.

Syntax:

int atoi(const char *strn)
Parameters: The function accepts one parameter strn, which refers to the string argument that needs to be converted into its integer equivalent.

Return Value: If strn is a valid input, the function returns the equivalent integer number for the passed string. If no valid conversion takes place, the function returns zero.



💡 Tip (In C): split the number by dividing it, and to get the rest, are you aware of the mod operator? You should Google it :)



🧪 TESTS TO CONSIDER
INPUT "2"
EXPECTED RETURN 2
INPUT "123"
EXPECTED RETURN 123
INPUT "-10"
EXPECTED RETURN -10
INPUT "" (empty string)
EXPECTED RETURN 0
INPUT "abc" (not a number)
EXPECTED RETURN 0
INPUT " 42" (leading spaces, like the real atoi)
EXPECTED RETURN Check whether you handle this case — the real atoi() ignores them
INPUT "+5" (explicit + sign)
EXPECTED RETURN 5
INPUT "42abc" (number followed by letters)
EXPECTED RETURN 42
💡 The real atoi() stops at the first invalid character instead of rejecting everything
INPUT "2147483648" (exceeds INT_MAX)
EXPECTED RETURN Undefined behavior — overflow trap


*/