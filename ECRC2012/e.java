import java.util.Scanner;
public class e {
	public static String[] resolve(String[] vals, int op)
	{
		int ind = 2*op + 1;
		if(ind + 1 >= vals.length)
		{
			System.err.println("Problem");
		}
		int x = Integer.parseInt(vals[ind-1]);
		int y = Integer.parseInt(vals[ind+1]);
		int res = 0;
		if(vals[ind].equals("+"))
			res = x + y;
		else if(vals[ind].equals("-"))
			res = x - y;
		else if(vals[ind].equals("*"))
			res = x * y;
		else
			System.err.println("problem2");
		
		String[] ret = new String[vals.length - 2];
		for(int i = 0; i < ind - 1; i++)
			ret[i] = vals[i];
		ret[ind-1] = res + "";
		for(int i = ind + 2; i < vals.length; i++)
			ret[i-2] = vals[i];
		return ret;
	}
	public static int solve(String vals[], boolean max, boolean print)
	{
		//System.err.println(expr);
		int bestVal;
		if(max)
			bestVal = Integer.MIN_VALUE;
		else
			bestVal = Integer.MAX_VALUE;
		int bestop = -1;
		if(vals.length == 3)
		{
			bestVal = Integer.parseInt(resolve(vals,0)[0]);
			bestop = 0;
		}
		else
		{
			for(int i = 0; i < (vals.length - 1)/2; i++)
			{
				String[] new_expr = resolve(vals, i);
				int ans = solve(new_expr, !max, false);
				if(max)
				{
					if(ans > bestVal)
					{
						bestVal = ans;
						bestop = i;
					}
				}
				else
				{
					if(ans < bestVal)
					{
						bestVal = ans;
						bestop = i;
					}
				}
				
			}
		}
		if(print)
		{
			if(max)
				System.out.println("Player 1 (" + vals[2*bestop] + vals[2*bestop+1] + vals[2*bestop+2] + ") leads to " + bestVal);
			else
				System.out.println("Player 2 (" + vals[2*bestop] + vals[2*bestop+1] + vals[2*bestop+2] + ") leads to " + bestVal);
		}
		return bestVal;
		
	}
	public static void main(String[] args)
	{
		Scanner s = new Scanner(System.in);
		int m = Integer.parseInt(s.nextLine());
		for(int t = 1; t <= m; t++)
		{
			String line = s.nextLine();
			String[] vals = line.split(" ");
			String[] newval = new String[vals.length - 1];
			for(int i = 0; i < vals.length-1; i++)
				newval[i] = vals[i+1];
			System.out.println("Case " + t + ":");
			int player1 = solve(newval, true, true);
			int player2 = solve(newval, false, true);
			if(player1 > -player2)
				System.out.println("Player 1 wins");
			else if(-player2 > player1)
				System.out.println("Player 2 wins");
			else
				System.out.println("Tie");
			
			
		}
	}
}

