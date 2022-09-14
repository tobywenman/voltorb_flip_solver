from queue import Empty


class game:
    hori=[[5,1],[3,2],[5,1],[4,1],[8,1]]
    vert=[[5,1],[5,1],[5,1],[4,2],[6,1]]
    pos=[0,0]
    grid = [["","","","",""],
             ["","","","",""],
             ["","","","",""],
             ["","","","",""],
             ["","","","",""],]
    
    def set_empty(self):
        for i in range(5):
            for j in range(5):
                if self.grid[i][j]=="":
                    self.pos=[i,j]
                    return True
        return False
    
    
    def solve(self):
        
        if(not self.set_empty()):
            return True
        
        for val in ["v","1","2","3"]:
            print("val: ",val)
            if self.checkSafe(val):
                
                if self.solve():
                    print("solution found: ", self.grid)
        return False
            
        
    
    def checkSafe(self, val):
        
        prev = self.grid[self.pos[0]][self.pos[1]]
        print(self.grid, self.pos)
        self.grid[self.pos[0]][self.pos[1]] = val
        print(self.grid, self.pos)
        vcoin = 0
        vvolt = 0
        vun = 0
        hcoin = 0
        hvolt = 0
        hun = 0
        for i in range(0,5):
            h = self.grid[self.pos[0]][i]
            v = self.grid[i][self.pos[1]]
            
            if v == "":
                vun += 1
            elif v == "v":
                vvolt += 1
            elif v == "1":
                vcoin += 1
            elif v == "2":
                vcoin += 2
            elif v == "3":
                vcoin += 3
            
            if h == "":
                hun += 1
            elif h == "v":
                hvolt += 1
            elif h == "1":
                hcoin += 1
            elif h == "2":
                hcoin += 2
            elif h == "3":
                hcoin += 3     
        
        vexcessV = self.vert[self.pos[1]][1]-vvolt
        hexcessV = self.hori[self.pos[0]][1]-hvolt
        
        vexcessU = vun - vexcessV
        hexcessU = hun - hexcessV
        
        vneedCoin = self.vert[self.pos[1]][0] - vcoin
        hneedCoin = self.hori[self.pos[0]][0]-hcoin
        
        if vexcessV < 0 or hexcessV < 0:
            self.grid[self.pos[0]][self.pos[1]] = prev
            print("excess v\n")
            return False
        
        if vneedCoin > vexcessU*3 or hneedCoin > hexcessU*3:
            self.grid[self.pos[0]][self.pos[1]] = prev
            print("not enough coin\n")
            return False
        
        if self.vert[self.pos[1]][0] < vcoin or self.hori[self.pos[0]][0] < hcoin:
            self.grid[self.pos[0]][self.pos[1]] = prev
            print("too many coin\n")
            return False
        
        
        print("valid\n")
        return True
                
if __name__=="__main__":
    newGame = game()
    
    print(newGame.solve())
    print(newGame.grid)