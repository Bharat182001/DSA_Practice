// https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implementing-floyd-warshall2042

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	   // TC: O(n*n*n)
	    int n=matrix.size();
	    
	// making our adjacency matrix to be (if a node is unreachable: update its cost to 1e9)
	    for(int i=0; i<n; i++) {
	        for(int j=0; j<n; j++){
	            if(matrix[i][j] ==-1) matrix[i][j]=1e9;
	            if(i==j) matrix[i][j]=0;
	        }
	    }
	    
	    // trying updating adjacency matrix when travelled via nodes(0->n-1)
	    for(int via=0; via<n; via++) {
	        for(int i=0; i<n; i++) {
	            for(int j=0; j<n; j++) {
	                matrix[i][j] = min(matrix[i][j], (matrix[i][via] + matrix[via][j]));
	            }
	        }
	    }
	    
	    // A check for negative cycle: IF INTERVIEWER ASKS ABOUT THAT
	   // for(int i=0; i<n; i++) {
	   //     if(matrix[i][i] < 0) {
	   //         cout<<"Negative Cycle exists\n";
	   //         break;
	   //     }
	   // }
	    
	    // as per question, we need to assign -1 if any node is unreachable
	    for(int i=0; i<n; i++) {
	        for(int j=0; j<n; j++) {
	            if(matrix[i][j]==1e9) matrix[i][j]=-1; 
	        }
	    }
	    
	    return;
	}
};
