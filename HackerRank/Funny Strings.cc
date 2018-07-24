using System;
using System.Collections.Generic;
using System.IO;
class Solution
{
    static void Main(String[] args)
    {
        int T,b;
        String S,R;
       
        T=Convert.ToInt32(Console.ReadLine());
        for(int i=0;i<T;i++)
        {
            S = Console.ReadLine();
            R = "";
            b = 0;
            for (int e = S.Length - 1; e >= 0; e--)
                R += S[e];
            for(int e=1;e<S.Length;e++)
            {
                if (Math.Abs(S[e] - S[e - 1]) != Math.Abs(R[e] - R[e - 1]))
                {
                    Console.WriteLine("Not Funny");
                    b = 1;
                    break;
                }
                if (b == 1)
                    break;
            }
            if (b == 0)
                Console.WriteLine("Funny");

        }
       
    }
}