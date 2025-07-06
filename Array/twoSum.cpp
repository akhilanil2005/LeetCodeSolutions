#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int na = int(A.size()), nb = int(B.size());
        int n = na + nb;
        if (n % 2) {
            return solve(A, B, n / 2, 0, na - 1, 0, nb - 1);
        } else {
            return 1.0 *
                   (solve(A, B, n / 2 - 1, 0, na - 1, 0, nb - 1) +
                    solve(A, B, n / 2, 0, na - 1, 0, nb - 1)) / 2;
        }
    }

private:
    int solve(vector<int>& A, vector<int>& B, int k, int aStart, int aEnd,
              int bStart, int bEnd) {
        if (aEnd < aStart) return B[k - aStart];
        if (bEnd < bStart) return A[k - bStart];

        int aIndex = (aStart + aEnd) / 2;
        int bIndex = (bStart + bEnd) / 2;
        int aValue = A[aIndex], bValue = B[bIndex];

        if (aIndex + bIndex < k) {
            if (aValue > bValue) {
                return solve(A, B, k, aStart, aEnd, bIndex + 1, bEnd);
            } else {
                return solve(A, B, k, aIndex + 1, aEnd, bStart, bEnd);
            }
        } else {
            if (aValue > bValue) {
                return solve(A, B, k, aStart, aIndex - 1, bStart, bEnd);
            } else {
                return solve(A, B, k, aStart, aEnd, bStart, bIndex - 1);
            }
        }
    }
};

int main() {
    int n1, n2;
    cout << "Enter number of elements in first sorted array: ";
    cin >> n1;
    vector<int> A(n1);
    cout << "Enter elements of first sorted array: ";
    for (int i = 0; i < n1; i++) cin >> A[i];

    cout << "Enter number of elements in second sorted array: ";
    cin >> n2;
    vector<int> B(n2);
    cout << "Enter elements of second sorted array: ";
    for (int i = 0; i < n2; i++) cin >> B[i];

    Solution sol;
    double median = sol.findMedianSortedArrays(A, B);
    cout << "Median is: " << median << endl;

    return 0;
}



/*hello*/