class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0,j=0;
        int n1 = version1.length(),n2 = version2.length();
        while(i<n1 || j<n2){
            string s1 = "";
            while(i<n1 && version1[i] != '.'){
                s1 += version1[i];
                i++;
            }
            string s2 = "";
            while(j<n2 && version2[j] != '.'){
                s2 += version2[j];
                j++;
            }
            int num1 = 0,num2 = 0;
            if(s1 != "")num1 = stoi(s1);
            if(s2 != "")num2 = stoi(s2);
            if(num1 > num2)return 1;
            else if(num1 < num2)return -1;
            i++;j++;
        }
        return 0;
    }
};