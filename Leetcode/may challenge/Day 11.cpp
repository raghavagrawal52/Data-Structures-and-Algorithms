// This problem is solved using the standard floodfill algorithm 
// check the geeksforgeeks page for more info

class Solution {
public:
    void paint(vector<vector<int>>& image, int sr, int sc,int prevColor, int newColor){
        int row_n = image.size();
        int col_n = image[0].size();
        
        if(sr<0 || sr>=row_n || sc<0 || sc>=col_n)
            return;
        if(image[sr][sc] != prevColor)
            return;
        if(image[sr][sc] == newColor)
            return;
        
        image[sr][sc] = newColor;

        paint(image,sr+1,sc,prevColor,newColor);
        paint(image,sr-1,sc,prevColor,newColor);
        paint(image,sr,sc+1,prevColor,newColor);
        paint(image,sr,sc-1,prevColor,newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int prevColor = image[sr][sc];
        paint(image,sr,sc,prevColor,newColor);
        return image;
    }
};
