 
# This file is auto-generated from a Python script that parses a PhysiCell configuration (.xml) file.
#
# Edit at your own risk.
#
import os
from ipywidgets import Label,Text,Checkbox,Button,HBox,VBox,FloatText,IntText,BoundedIntText,BoundedFloatText,Layout,Box
    
class UserTab(object):

    def __init__(self):
        
        micron_units = Label('micron')   # use "option m" (Mac, for micro symbol)

        constWidth = '180px'
        tab_height = '500px'
        stepsize = 10

        #style = {'description_width': '250px'}
        style = {'description_width': '25%'}
        layout = {'width': '400px'}

        name_button_layout={'width':'25%'}
        widget_layout = {'width': '15%'}
        units_button_layout ={'width':'15%'}
        desc_button_layout={'width':'45%'}

        param_name1 = Button(description='Apply_Dirichlet_on_right_edge', disabled=True, layout=name_button_layout)
        param_name1.style.button_color = 'lightgreen'

        self.Apply_Dirichlet_on_right_edge = Checkbox(
          value=True,
          style=style, layout=widget_layout)

        param_name2 = Button(description='Apply_Dirichlet_on_left_edge', disabled=True, layout=name_button_layout)
        param_name2.style.button_color = 'tan'

        self.Apply_Dirichlet_on_left_edge = Checkbox(
          value=True,
          style=style, layout=widget_layout)

        param_name3 = Button(description='Apply_Dirichlet_on_top_edge', disabled=True, layout=name_button_layout)
        param_name3.style.button_color = 'lightgreen'

        self.Apply_Dirichlet_on_top_edge = Checkbox(
          value=True,
          style=style, layout=widget_layout)

        param_name4 = Button(description='Apply_Dirichlet_on_bottom_edge', disabled=True, layout=name_button_layout)
        param_name4.style.button_color = 'tan'

        self.Apply_Dirichlet_on_bottom_edge = Checkbox(
          value=True,
          style=style, layout=widget_layout)

        param_name5 = Button(description='make_Dirichlet_node', disabled=True, layout=name_button_layout)
        param_name5.style.button_color = 'lightgreen'

        self.make_Dirichlet_node = Checkbox(
          value=True,
          style=style, layout=widget_layout)

        param_name6 = Button(description='Dirichlet_node_position_x', disabled=True, layout=name_button_layout)
        param_name6.style.button_color = 'tan'

        self.Dirichlet_node_position_x = FloatText(
          value=100.0,
          step=10,
          style=style, layout=widget_layout)

        param_name7 = Button(description='Dirichlet_node_position_y', disabled=True, layout=name_button_layout)
        param_name7.style.button_color = 'lightgreen'

        self.Dirichlet_node_position_y = FloatText(
          value=100.0,
          step=10,
          style=style, layout=widget_layout)

        param_name8 = Button(description='Concentration_of_oxygen', disabled=True, layout=name_button_layout)
        param_name8.style.button_color = 'tan'

        self.Concentration_of_oxygen = FloatText(
          value=0.0,
          step=0.01,
          style=style, layout=widget_layout)

        param_name9 = Button(description='Concentration_of_Chemical_A', disabled=True, layout=name_button_layout)
        param_name9.style.button_color = 'lightgreen'

        self.Concentration_of_Chemical_A = FloatText(
          value=0.0,
          step=0.01,
          style=style, layout=widget_layout)

        units_button1 = Button(description='', disabled=True, layout=units_button_layout) 
        units_button1.style.button_color = 'lightgreen'
        units_button2 = Button(description='', disabled=True, layout=units_button_layout) 
        units_button2.style.button_color = 'tan'
        units_button3 = Button(description='', disabled=True, layout=units_button_layout) 
        units_button3.style.button_color = 'lightgreen'
        units_button4 = Button(description='', disabled=True, layout=units_button_layout) 
        units_button4.style.button_color = 'tan'
        units_button5 = Button(description='', disabled=True, layout=units_button_layout) 
        units_button5.style.button_color = 'lightgreen'
        units_button6 = Button(description='', disabled=True, layout=units_button_layout) 
        units_button6.style.button_color = 'tan'
        units_button7 = Button(description='', disabled=True, layout=units_button_layout) 
        units_button7.style.button_color = 'lightgreen'
        units_button8 = Button(description='', disabled=True, layout=units_button_layout) 
        units_button8.style.button_color = 'tan'
        units_button9 = Button(description='', disabled=True, layout=units_button_layout) 
        units_button9.style.button_color = 'lightgreen'

        desc_button1 = Button(description='', disabled=True, layout=desc_button_layout) 
        desc_button1.style.button_color = 'lightgreen'
        desc_button2 = Button(description='', disabled=True, layout=desc_button_layout) 
        desc_button2.style.button_color = 'tan'
        desc_button3 = Button(description='', disabled=True, layout=desc_button_layout) 
        desc_button3.style.button_color = 'lightgreen'
        desc_button4 = Button(description='', disabled=True, layout=desc_button_layout) 
        desc_button4.style.button_color = 'tan'
        desc_button5 = Button(description='', disabled=True, layout=desc_button_layout) 
        desc_button5.style.button_color = 'lightgreen'
        desc_button6 = Button(description='value on x-axis for dirichlet node; make sure it is within domain size', disabled=True, layout=desc_button_layout) 
        desc_button6.style.button_color = 'tan'
        desc_button7 = Button(description='value on y-axis for dirichlet node; make sure it is within domain size', disabled=True, layout=desc_button_layout) 
        desc_button7.style.button_color = 'lightgreen'
        desc_button8 = Button(description='concentration of oxygen at this specific Dirichlet node', disabled=True, layout=desc_button_layout) 
        desc_button8.style.button_color = 'tan'
        desc_button9 = Button(description='concentration of Chemical_A at this specific Dirichlet node', disabled=True, layout=desc_button_layout) 
        desc_button9.style.button_color = 'lightgreen'

        row1 = [param_name1, self.Apply_Dirichlet_on_right_edge, units_button1, desc_button1] 
        row2 = [param_name2, self.Apply_Dirichlet_on_left_edge, units_button2, desc_button2] 
        row3 = [param_name3, self.Apply_Dirichlet_on_top_edge, units_button3, desc_button3] 
        row4 = [param_name4, self.Apply_Dirichlet_on_bottom_edge, units_button4, desc_button4] 
        row5 = [param_name5, self.make_Dirichlet_node, units_button5, desc_button5] 
        row6 = [param_name6, self.Dirichlet_node_position_x, units_button6, desc_button6] 
        row7 = [param_name7, self.Dirichlet_node_position_y, units_button7, desc_button7] 
        row8 = [param_name8, self.Concentration_of_oxygen, units_button8, desc_button8] 
        row9 = [param_name9, self.Concentration_of_Chemical_A, units_button9, desc_button9] 

        box_layout = Layout(display='flex', flex_flow='row', align_items='stretch', width='100%')
        box1 = Box(children=row1, layout=box_layout)
        box2 = Box(children=row2, layout=box_layout)
        box3 = Box(children=row3, layout=box_layout)
        box4 = Box(children=row4, layout=box_layout)
        box5 = Box(children=row5, layout=box_layout)
        box6 = Box(children=row6, layout=box_layout)
        box7 = Box(children=row7, layout=box_layout)
        box8 = Box(children=row8, layout=box_layout)
        box9 = Box(children=row9, layout=box_layout)

        self.tab = VBox([
          box1,
          box2,
          box3,
          box4,
          box5,
          box6,
          box7,
          box8,
          box9,
        ])

    # Populate the GUI widgets with values from the XML
    def fill_gui(self, xml_root):
        uep = xml_root.find('.//microenvironment_setup')  # find unique entry point
        vp = []   # pointers to <variable> nodes
        if uep:
            for var in uep.findall('variable'):
                vp.append(var)

        uep = xml_root.find('.//user_parameters')  # find unique entry point
        self.Apply_Dirichlet_on_right_edge.value = ('true' == (uep.find('.//Apply_Dirichlet_on_right_edge').text.lower()) )
        self.Apply_Dirichlet_on_left_edge.value = ('true' == (uep.find('.//Apply_Dirichlet_on_left_edge').text.lower()) )
        self.Apply_Dirichlet_on_top_edge.value = ('true' == (uep.find('.//Apply_Dirichlet_on_top_edge').text.lower()) )
        self.Apply_Dirichlet_on_bottom_edge.value = ('true' == (uep.find('.//Apply_Dirichlet_on_bottom_edge').text.lower()) )
        self.make_Dirichlet_node.value = ('true' == (uep.find('.//make_Dirichlet_node').text.lower()) )
        self.Dirichlet_node_position_x.value = float(uep.find('.//Dirichlet_node_position_x').text)
        self.Dirichlet_node_position_y.value = float(uep.find('.//Dirichlet_node_position_y').text)
        self.Concentration_of_oxygen.value = float(uep.find('.//Concentration_of_oxygen').text)
        self.Concentration_of_Chemical_A.value = float(uep.find('.//Concentration_of_Chemical_A').text)


    # Read values from the GUI widgets to enable editing XML
    def fill_xml(self, xml_root):
        uep = xml_root.find('.//microenvironment_setup')  # find unique entry point
        vp = []   # pointers to <variable> nodes
        if uep:
            for var in uep.findall('variable'):
                vp.append(var)

        uep = xml_root.find('.//user_parameters')  # find unique entry point
        uep.find('.//Apply_Dirichlet_on_right_edge').text = str(self.Apply_Dirichlet_on_right_edge.value)
        uep.find('.//Apply_Dirichlet_on_left_edge').text = str(self.Apply_Dirichlet_on_left_edge.value)
        uep.find('.//Apply_Dirichlet_on_top_edge').text = str(self.Apply_Dirichlet_on_top_edge.value)
        uep.find('.//Apply_Dirichlet_on_bottom_edge').text = str(self.Apply_Dirichlet_on_bottom_edge.value)
        uep.find('.//make_Dirichlet_node').text = str(self.make_Dirichlet_node.value)
        uep.find('.//Dirichlet_node_position_x').text = str(self.Dirichlet_node_position_x.value)
        uep.find('.//Dirichlet_node_position_y').text = str(self.Dirichlet_node_position_y.value)
        uep.find('.//Concentration_of_oxygen').text = str(self.Concentration_of_oxygen.value)
        uep.find('.//Concentration_of_Chemical_A').text = str(self.Concentration_of_Chemical_A.value)
