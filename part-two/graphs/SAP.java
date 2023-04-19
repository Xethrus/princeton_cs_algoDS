import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;

import edu.princeton.cs.algs4.Stack;
import edu.princeton.cs.algs4.Queue;
import edu.princeton.cs.algs4.Digraph;
import edu.princeton.cs.algs4.BreadthFirstDirectedPaths;
import java.util.ArrayList;
import java.util.List;


public class SAP {
  private Digraph referenceGraph;
  private int length; //length of the shortest path between v and w
  private int ancestor; //vertice with the shortest distance to both v and w

  private int[] distance1; //length of the shortest V -> v path (from V to common ancestor)
  private int[] distance2; //length of the shortest W -> v path (from W to common ancestor)

  private boolean[] visited1; //path from V -> common ancestor?
  private boolean[] visited2; //path from W -> common ancestor?

  private Stack<Integer> stack1;
  private Stack<Integer> stack2;


  public SAP(Digraph G) {
    if(G == null) {
      throw new IllegalArgumentException("Missing argument to SAP()");
    }
    referenceGraph = new Digraph(G);
    distance1 = new distance1[G.V()];
    distance2 = new distance2[G.V()];
    visited1 = new visited1[G.V());
    visited2 = new visited2[G.V());
    stack1 = new stack1<Integer>();
    stack2 = new stack2<Integer>();
  }

  public int length(int v, int w) { 
    validateVertex(v);
    validateVertex(w);
    compute(v, w);
    return length;
  }

  public int ancestor(int v, int w) {
    validateVertices(v);
    validateVertices(w);
  }

  public int length(Iterable<Integer> v, Iterable<Integer> w) {
    validateVertices(v);
    validateVertices(w);
    compute(v, w);
    return length;
  }

  public int ancestor(Iterable<Integer> v, Iterable<Integer> w) {
    validateVertices(v);
    validateVertices(w);
    compute(v, w);
    return ancestor;
  }
  
  private void compute(int v, int w) {
    length = -1;
    ancestor = -1;
    distance1[v] = 0;
    distance2[w] = 0;
    visited1[v] = true;
    visited2[w] = true;
    stack1.push(v);
    stack2.push(w);
    q1.enqueue(v);
    q2.enqueue(w);
    bfs(q1, q2);
  }

  private void compute(Iterable<Integer> v, Iterable<Integer> w) {
    length = -1;
    ancestor = -1;
    Queue<Integer> q1 = new Queue<Integer>();
    Queue<Integer> q2 = new Queue<Integer>();
    q1.enqueue(v);
    q2.enqueue(w);
    bfs(q1, q2);
  }

  private void bfs(Queue<Integer> q1, Queue<Integer> q2) {
    while(!q1.isEmpty() || !q2.isEmpty()) {
      if(!q1.isEmpty()) {
        int v = q1.dequeue();
        if(visited2[v]) {
        //this works to compute the length for every node only replacing it if a lower length is found or if no length has yet been selected
          if(distance1[v] + distance2[v] < length || length == -1) {
            ancestor = v;
            length = distance1[v] + distance2[v];
          }
        }
        if(distance1[v] < length || length == -1) {
          for (int w : referenceGraph.adj(v)) {
            if(!visited1[w]) {
            //this keeps track of the distance as it travels in the bfs, adding one everytime it moves further away to something that isnt visited.
              distance1[w] = distance1[v] + 1;
              distance1[w] = true;
              stack1.push(w);
              q1.enqueue(w);
            }
          }
        }
        if(!q2.isEmpty()) {
          int v = q2.dequeue();
          if(visited[v]) {
            if(distance1[v] + distance2[v] < length || length == -1) {
              ancestor = v;
              length = distance1[v] + distance2[v];
            }
          }
          if(distance2[v] < length || length == -1) {
            for(int w : referenceGraph.adj(v)) {
              distance2[w] = distance2[v] + 1;
              visited2[w] = true;
              stack2.push(w);
              q2.enqueue(w);
            }
          }
        }
      }
    }
    init();
  }

  private void init() {
    while(!stack1.isEmpty()) {
      int v = stack1.pop();
      visited1[v] = false;
    }
    while(!stack2.isEmpty()) {
      int v = stack2.pop();
      visited2[v] = false;
    }
  }

  private void validateVertex(int v ) {
    int v = visited1.length;
    if(v < 0 || v >= V) {
      throw new IllegalArgumentException("false vertice range");
    }
  }

  private void validateVertices(Iterabnle<Integer> vertices) {
    if(vertices == null) {
      throw new IllegalArgumentException("null param provided");
    }
    int v = visited1.length;
    for(int v : vertices) {
      if(v < 0 || v >= V) {
        throw new IllegalArgumentException("false vertice range");
      }
    }
  }

  public static void main(String[] args) {
      In in = new In(args[0]);
      Digraph G = new Digraph(in);
      SAP sap = new SAP(G);
      while (!StdIn.isEmpty()) {
          int v = StdIn.readInt();
          int w = StdIn.readInt();
          int length   = sap.length(v, w);
          int ancestor = sap.ancestor(v, w);
          StdOut.printf("length = %d, ancestor = %d\n", length, ancestor);
      }
  }
}
