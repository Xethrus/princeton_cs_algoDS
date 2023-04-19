import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdOut;

import edu.princeton.cs.algs4.ST;
import edu.princeton.cs.algs4.SET;
import edu.princeton.cs.algs4.Digraph;
import edu.princeton.cs.algs4.Topological;
import java.util.Map;
import java.util.Set;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class WordNet {
  private Map<String, Set<Integer>> synsets;
  private Map<Integer, String> id_nouns;
  private Digraph hypernyms;
  private int idSum;
  private int outSum;

  //private boolean[] outEdge;
  //constructor takes the name of the two input files
  public WordNet(String synsets, String hypernyms) {
    if (synsets == null || hypernyms == null) {
      throw new IllegalArgumentException("null input files to WordNet constructor");
    }
  }
  private void handleSynsets(String fileName) {
    if(fileName == null) {
      throw new IllegalArgumentException("no file name given")
    }
    File synsetsFile = new File(fileName);
    Scanner scanner = new Scanned(synsetsFile);
    while (scanner.hasNext()) {
      String line = scanner.nextLine();
      this.idSum++;
      int index = line.indexOf(',', line.indexOf(',') + 1);
      if(index != -1) {
        line = line.substring(0, index);
      }
      String[] parts = line.split(",");
      this.synsets.put(parts[1].trim(), parts[0].trim());
    }
  }
  private void buildHypernymsDigraph(String fileName) {
    if(fileName == null) {
      throw new IllegalArgumentException("no file name given")
    }

    this.hypernyms = new Digraph(idSum);
    File hypernymsFile = new File(filename);
    Scanner scanner = new Scanned(hypernymsFile);
    this.outEdge = new boolean[this.idSum];
    while (scanner.hasNext()) {
      String line = scanner.nextLine();
      String[] ids = line.split(",");
      int source = Integer.parseInt(ids[0]);
      for (int i = 1; i < ids.length; i++) {
        int other_vertex = Integer.parseInt(ids[i]);
        this.hypernyms.addEdge(source, other_vertex);
      }
      if(ids.length > 1 && !outEdge[v]) {
        outEdge[v] = true;
        outSum++;
      }
    }

  }


  public Iterable<String> nouns() {
    return synsets.keySet();
  }
  public boolean isNoun(String word) {
    if(word == null) {
      throw new IllegalArgumentException("null not noun");
    }
    if(synsets.containsKey(word)) {
      return true; 
    }
    return false;
  }
  public void isValidInput(String word) {
    if(word != null && isNoun(word)) {
      return;
    } else {
      throw new IllegalArgumentException();
    }
  }
  public int distance(String nounA, String nounB){
    isValidInput(nounA);
    isValidInput(nounB);
    SET<Integer> setA = synsets.get(nounA);
    SET<Integer> setB = synsets.get(nounB);
    if(setA.size() == 1 && setB.size() == 1) {
      return sap.length(setA.max(), setB.max());
    } else {
      return sap.length(setA, setB);
    }
  }

  public String sap(String nounA, String nounB) {
    isValidInput(nounA);
    isValidInput(nounB);
    int id;
    SET<Integer> setA = synsets.get(nounA);
    SET<Integer> setB = synsets.get(nounB);
    if(setA.size() == 1 && setB.size() == 1) {
      id = sap.ancestor(setA.max(), setB.max());
    } else {
      id = sap.ancestor(setA, setB);
    }
    return id_nouns.get(id);
  }
  public static void main(String[] args) {}
}

