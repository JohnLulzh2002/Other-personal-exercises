import java.nio.file.*;
import java.io.*;
public class Main {
	public static void main(String[] args) throws IOException{
		int firstCity=50136,maxStation=0,maxRainfall=0;
		int[] rainfall=new int[9999];
		String[] ms={"01","02","03","04","05","06","07","08",/*"09","10",*/"11","12"};
		for(String m:ms){
			String p="SURF_CLI_CHN_MUL_DAY-PRE-13011-2008"+m+".TXT";
			System.out.println("Read: "+p);
			for(String line:Files.readAllLines(Path.of(p))){
				// System.out.println(line);
				String ss[]=line.split(" +");
				int station=Integer.parseInt(ss[0])-firstCity;
				rainfall[station]+=Integer.parseInt(ss[9]);
			}
		}
		for(int i=0;i<9999;i++)
			if(maxRainfall<rainfall[i]){
				maxRainfall=rainfall[i];
				maxStation=i;
			}
		System.out.printf("The station with maximum rainfall is: %d\n",maxStation+firstCity);
		System.out.printf("Its total rainfall is: %d mm\n",maxRainfall);
		// System.out.println(maxStation+firstCity);
	}
}