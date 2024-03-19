class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>fq(26,0);
        for(int i=0;i<tasks.size();i++)
        {
            fq[tasks[i]-'A']++;
        }
        sort(fq.rbegin(),fq.rend());
          int gap=fq[0]-1;
          int idle=n*gap;
        //minimise the ideal by kepping other elements
          for(int i=1;i<26;i++)
          {
            idle=idle-min(gap,fq[i]);
          }
          if(idle<0) return tasks.size();
          else return tasks.size()+idle;
            }
};
