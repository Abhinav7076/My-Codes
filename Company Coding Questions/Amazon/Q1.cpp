import java.util.ArrayList;

import java.util.Collections;

import java.util.HashMap; import java.util.List;

public class Techlandia {

static HashMap<String, List<String>> temp = new HashMap<>(); static ArrayList<String> values = new ArrayList<>();

static ArrayList<String> news = new ArrayList<>();

static HashMap<String, String> olds = new HashMap<>();

static List<String> results = new ArrayList<>();

public static void main(String[] args) {

List<String> boxList = new ArrayList<>(); boxList.add("ykc 82 01");

boxList.add("eo first qpx");

boxList.add("09z cat hamster");

boxList.add("06F 12 25 6");

boxList.add("az0 First qpx");

boxList.add("236 cat dog rabbit snake");

ordered JunctionBoxes(6, boxList).forEach(System.out.println);

}

public static List<String> ordered Junction Boxes(int numberOfBoxes,

List<String> boxList) {

boxList.forEach(a-> (

int p=a.indexOf(" ");

String version=a.substring(p+1);

String id=a.substring(0, p);

String[] vSplit = version.split(" ");

try {

Integer.parseInt(vSplit[0]);

news.add(a);

} catch (NumberFormatException nfe)

List<String> ls;

if((ls-temp.get(version)) == null) {

Is = new ArrayList<>();

Is.add(id);

temp.put(version, Is);

} else {

Is.add(id);

temp.put(version, Is);

}

olds.put(id, a);

values.add(version);
}
}),
Collections.sort(values);

values.forEach(a-> {

List<String> vals = temp.get(a); Collections.sort(vals);

vals.forEach(x-> {

results.add(olds.get(x));

temp.put(a, new ArrayList<String>());

news.forEach(a-> results.add(a));

return results;

}}