struct Square;

struct Line{
    Square *squares[5];
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
};


struct Game{
    Game();
    Line hLines[5];
    Line vLines[5];
    void solve();
    bool check();
};