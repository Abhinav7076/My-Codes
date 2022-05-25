// Step 1 : First we will take two arrays left_smaller[] and right_smaller[] and initialize it with -1 and n respectively.

// Step 2 : For every element we will store the index of previous smaller and next smaller element in left_smaller[] and right_smaller[] arrays respectively.

//                 (It will take O(n) time).

// Step 3 : Now for every element we will calculate area by taking this ith element as the smallest in the range left_smaller[i] and right_smaller[i] and multiplying it with the difference of left_smaller[i] and right_smaller[i].

// Step 4 : We can find the maximum of all the area calculated in step 3 to get the desired maximum area.

Which is the first block which is smaller than me Kyunki usko area me Nahi le sakte 

// Agar Chota hai to rakho Kyunki Hame left me pehla smaller chahiye : pattern is linearly increasing fashion 
// If top is not smaller pop it until you get next smaller 
// Time complexity : O(n) Kyunki Ham har bar we are not removing every element from the stack

class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long heights[], int n)
    {
      stack < long long > st;
      int leftsmall[n], rightsmall[n];
      for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
          st.pop();
        }
        if (st.empty())
          leftsmall[i] = 0;
        else
          leftsmall[i] = st.top() + 1;
        st.push(i);
      }
      // clear the stack to be re-used
      while (!st.empty())
        st.pop();

      for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i])
          st.pop();

        if (st.empty())
          rightsmall[i] = n - 1;
        else
          rightsmall[i] = st.top() - 1;

        st.push(i);
      }
      long long maxA = 0;
      for (int i = 0; i < n; i++) {
        maxA = max(maxA, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
      }
      return maxA;
    }
};
//Time complexity = O(n) + O(n)
//space complecity = 3*O(n)
// 2nd approach : agar pop kar rahe tabhi area nikalenge 
//----------------
//method 2
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long histo[], int n)
    {
      stack < int > st;
      long long maxA = 0;
      for (int i = 0; i <= n; i++) {
        while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
          long long height = histo[st.top()];
          st.pop();
          long long width;
          if (st.empty())
            width = i;
          else
            width = i - st.top() - 1;
          maxA = max(maxA, width * height);
        }
        st.push(i);
      }
      return maxA;
    }
};

//Time complexity = O(n) + O(n)
//space complecity = O(n)