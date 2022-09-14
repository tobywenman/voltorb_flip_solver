#include <fstream>

struct Square;

struct Line{
    Square *squares[5];
    int volts=0;
    int coins=0;
};

struct Square{
    int value=1;
    Line *lines[2];
    enum values{
        unknown,
        one,
        two,
        three,
        volt
    };
    values state=unknown;
    bool marked[4]={true,true,true,true};
    bool solve();
};


struct Game{
    Game();
    Line hLines[5];
    Line vLines[5];
    bool check();
    void cliInput();
    void output();
    void loop();
    void fileInput(std::string filename);
    std::ifstream file;
};