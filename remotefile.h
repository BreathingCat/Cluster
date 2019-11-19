#ifndef REMOTEFILE_H
#define REMOTEFILE_H


class remotefile
{

public:
    remotefile();

    // Opens file "filename", copies content in "buff"
    void readfile(char* filename, char** buff, unsigned long int* bufflen);
};

#endif // REMOTEFILE_H
