/* https://leetcode.com/articles/range-sum-query-immutable/
I copy it from another one .With the brute force will cause limit exceed
*/
class NumArray {
private:    
vector<int> temp;
public:
NumArray(vector<int> &nums) {
    int num = nums.size();
    temp.resize(num, 0);
    int tempsum = 0;
    for (int i = 0; i < num; i++)
    {
        tempsum += nums.at(i);
        temp.at(i) = tempsum;
    }
}

int sumRange(int i, int j) {
    if(i==0)
    {
        return temp.at(j);
    }
    else
    {
        return (temp.at(j)-temp.at(i-1));
    }
}
};
