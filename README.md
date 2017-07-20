# Plotter
Plotting Graphs from TXT Files
![Plotter](/images/plottericon.png?raw=true "Plotter")

Plotter is a QT based application written in C++ which helps in analyzing the data from txt file which contains data in any format with a separator or many separators(such as , . - \t) between two data(cell) and the rows are described on a unique line.

### Screenshot of UI
![PlotterSnapShot](/images/PlotterSnapShot.jpg?raw=true "ScreenShot of UI")

### Intructions:
1. Open a File
      - Select File->Open File 
         **or**
       - Click on ![OpenFile](/images/OpenFile.jpg?raw=true "OpenFile") 
       
   File box shows the location of the file that have been selected.
   Status box will says **DATA COLLECTED** if all the data is collected properly(including the separator symbols).
   
   
2. If the data shown in the table are all numbers than skip this step but if table contains *symbols*(from the txt files) than put all those separators in the separarator box and click **REFRESH Button** and check if the data in table is proper(ie, numbers).

    Status box will says **REFRESH DONE**
      **Notes:**
      - If the data have number are negative or have floating point **-** or **.** symbols than put **'- '**(for -) and **'. '** in the separator box.
      - Refresh Button can be used anytime to refresh the data from the txt file or to make use separators. 

3. All the data in the cells of table are numeric(including intergers and floating both), now click on **Plot Button** to plot the graph.
      Graph will be plotted.
      Status box will says **DATA PLOTTED**

4. To save the plotted graph
      - Select File-> Save Image
         **or**
      - Click on ![SaveImage](/images/saveimage-1.png?raw=true "Save Image") 
