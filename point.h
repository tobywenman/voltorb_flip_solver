struct Square;

struct Line{
    Square *squares[5];
};

struct Square{
    int value=1;
    Line *lines[2];
};


struct Game{
    Game();
    Line hLines[5];
    Line vLines[5];
};