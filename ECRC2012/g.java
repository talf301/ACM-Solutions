import java.util.Arrays;
import java.util.Scanner;
import java.util.HashSet;
import java.util.ArrayList;
public class g {
	public static void main(String[] args)
	{
		Scanner s = new Scanner(System.in);
		int t = 0;
		while(true)
		{
			String in = s.nextLine();
			int n = Integer.parseInt(in);
			HashSet<String> names = new HashSet<String>();
			if(n == 0)
				break;
			t++;
			String[] lines = new String[n];
			for(int i = 0; i < n; i++)
			{
				lines[i] = s.nextLine();
				String[] vals = lines[i].split(" ");
				names.add(vals[1]);
				names.add(vals[4]);
			}
			String[] nnames = {};
			nnames = names.toArray(nnames);
			Arrays.sort(nnames);
			int num_names = nnames.length;
			frac[][] g = new frac[num_names][num_names];
			for(int i = 0; i < num_names; i++)
			{
				for(int j = 0; j < num_names; j++)
					g[i][j] = null;
			}
			for(int i = 0; i < num_names; i++)
				g[i][i] = new frac(1,1);
			for(int i = 0; i < n; i++)
			{
				String[] vals = lines[i].split(" ");
				int val1 = Integer.parseInt(vals[0]);
				int val2 = Integer.parseInt(vals[3]);
				int ind1 = find(nnames, vals[1]);
				int ind2 = find(nnames, vals[4]);
				long d = gcd(val1, val2);
				val1 /= d;
				val2 /= d;
				//System.err.println(vals[1]);
				g[ind1][ind2] = new frac(val2, val1);
				g[ind2][ind1] = new frac(val1, val2);
			}
			String line = s.nextLine();
			int wanted = Integer.parseInt(line.split(" ")[0]);
			int wantind = find(nnames, line.split(" ")[1]);
			boolean seen[] = new boolean[num_names];
			expand(g, seen, wantind);
			//System.err.println("here");
			double diff = Double.MAX_VALUE;
			int diff_req = 0;
			int diff_ind = 0;
			for(int i = 0; i < g.length; i++)
			{
				if(g[wantind][i] == null) continue;
				if(wantind == i) continue;
				int req = (int) Math.ceil(g[wantind][i].toFloat() * (double)wanted);
				if(req <= 100000 && req * g[wantind][i].invFloat() - wanted < diff)
				{
					//System.err.println(g[wantind][i].num + " " + g[wantind][i].denom + " " + req);
					diff = req * g[wantind][i].invFloat() - wanted;
					diff_req = req;
					diff_ind = i;
				}
			}
			//System.err.println(diff);
			System.out.println("Case " + t + ": " + diff_req + " " + nnames[diff_ind]);
		}
	}
	public static int find(String[] names, String name)
	{
		for(int i = 0; i < names.length; i++)
			if(name.equals(names[i]))
				return i;
		return -1;
	}
	
	public static long gcd(long a, long b)
	{ return (b == 0? a : gcd(b,a%b));}
	
	public static void expand(frac[][] g, boolean[] seen, int start)
	{
		//System.err.println(seen[start]);
		if(seen[start]) return;
		seen[start] = true;
		for(int i = 0; i < g.length; i++)
		{
			if(g[start][i] == null) continue;
			if(i == start) continue;
			expand(g, seen, i);
			for(int j = 0; j < g.length; j++)
			{
				if(g[start][j] != null) continue;
				if(g[i][j] == null) continue;
				g[start][j] = g[start][i].multiply(g[i][j]);
			}
		}
	}
}

class frac
{
	long num, denom;
	public frac(long a, long b)
	{
		num = a;
		denom = b;
	}
	
	public frac multiply(frac other)
	{
		long nnum = this.num * other.num;
		long nden = this.denom * other.denom;
		long d = g.gcd(nnum, nden);
		return new frac(nnum/d, nden/d);
	}
	public double toFloat()
	{
		return (double)num/(double)denom;
	}
	public double invFloat()
	{
		return (double)denom/(double)num;
	}
}
