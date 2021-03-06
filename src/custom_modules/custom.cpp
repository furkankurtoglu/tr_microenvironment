/*
###############################################################################
# If you use PhysiCell in your project, please cite PhysiCell and the version #
# number, such as below:                                                      #
#                                                                             #
# We implemented and solved the model using PhysiCell (Version x.y.z) [1].    #
#                                                                             #
# [1] A Ghaffarizadeh, R Heiland, SH Friedman, SM Mumenthaler, and P Macklin, #
#     PhysiCell: an Open Source Physics-Based Cell Simulator for Multicellu-  #
#     lar Systems, PLoS Comput. Biol. 14(2): e1005991, 2018                   #
#     DOI: 10.1371/journal.pcbi.1005991                                       #
#                                                                             #
# See VERSION.txt or call get_PhysiCell_version() to get the current version  #
#     x.y.z. Call display_citations() to get detailed information on all cite-#
#     able software used in your PhysiCell application.                       #
#                                                                             #
# Because PhysiCell extensively uses BioFVM, we suggest you also cite BioFVM  #
#     as below:                                                               #
#                                                                             #
# We implemented and solved the model using PhysiCell (Version x.y.z) [1],    #
# with BioFVM [2] to solve the transport equations.                           #
#                                                                             #
# [1] A Ghaffarizadeh, R Heiland, SH Friedman, SM Mumenthaler, and P Macklin, #
#     PhysiCell: an Open Source Physics-Based Cell Simulator for Multicellu-  #
#     lar Systems, PLoS Comput. Biol. 14(2): e1005991, 2018                   #
#     DOI: 10.1371/journal.pcbi.1005991                                       #
#                                                                             #
# [2] A Ghaffarizadeh, SH Friedman, and P Macklin, BioFVM: an efficient para- #
#     llelized diffusive transport solver for 3-D biological simulations,     #
#     Bioinformatics 32(8): 1256-8, 2016. DOI: 10.1093/bioinformatics/btv730  #
#                                                                             #
###############################################################################
#                                                                             #
# BSD 3-Clause License (see https://opensource.org/licenses/BSD-3-Clause)     #
#                                                                             #
# Copyright (c) 2015-2018, Paul Macklin and the PhysiCell Project             #
# All rights reserved.                                                        #
#                                                                             #
# Redistribution and use in source and binary forms, with or without          #
# modification, are permitted provided that the following conditions are met: #
#                                                                             #
# 1. Redistributions of source code must retain the above copyright notice,   #
# this list of conditions and the following disclaimer.                       #
#                                                                             #
# 2. Redistributions in binary form must reproduce the above copyright        #
# notice, this list of conditions and the following disclaimer in the         #
# documentation and/or other materials provided with the distribution.        #
#                                                                             #
# 3. Neither the name of the copyright holder nor the names of its            #
# contributors may be used to endorse or promote products derived from this   #
# software without specific prior written permission.                         #
#                                                                             #
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" #
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   #
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  #
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE   #
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR         #
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF        #
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    #
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN     #
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)     #
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  #
# POSSIBILITY OF SUCH DAMAGE.                                                 #
#                                                                             #
###############################################################################
*/

#include "./custom.h"

// declare cell definitions here 

Cell_Definition CellA; 

void create_cell_types( void )
{
	// use the same random seed so that future experiments have the 
	// same initial histogram of oncoprotein, even if threading means 
	// that future division and other events are still not identical 
	// for all runs 
	
		SeedRandom( parameters.ints("random_seed") ); // or specify a seed here 
	
	// housekeeping 
	
		
	initialize_default_cell_definition();
	cell_defaults.phenotype.secretion.sync_to_microenvironment( &microenvironment ); 
		
	//cell_defaults.phenotype.secretion.sync_to_microenvironment( &microenvironment ); 
	
	// Name the default cell type 
	
	cell_defaults.type = 0; 
	cell_defaults.name = "Model_Cell"; 
	
	// set default cell cycle model 

	cell_defaults.functions.cycle_model = live; 
	
	// set default_cell_functions; 
	
	cell_defaults.functions.update_phenotype = NULL; 
	
	// needed for a 2-D simulation: 
	
	/* grab code from heterogeneity */ 
	
	cell_defaults.functions.set_orientation = up_orientation; 
	cell_defaults.phenotype.geometry.polarity = 1.0;
	cell_defaults.phenotype.motility.restrict_to_2D = true; 
	
	// make sure the defaults are self-consistent. 
	
	cell_defaults.phenotype.secretion.sync_to_microenvironment( &microenvironment );
	cell_defaults.phenotype.sync_to_functions( cell_defaults.functions ); 

	// set the rate terms in the default phenotype 

	// first find index for a few key variables. 
	int apoptosis_model_index = cell_defaults.phenotype.death.find_death_model_index( "Apoptosis" );
	int necrosis_model_index = cell_defaults.phenotype.death.find_death_model_index( "Necrosis" );
	//int oxygen_substrate_index = microenvironment.find_density_index( "oxygen" ); 

	//int live_index = live_cycle_model.find_phase_index( PhysiCell_constants::live );
	//int S_index = flow_cytometry_separated_cycle_model.find_phase_index( PhysiCell_constants::S_phase );

	// initially no necrosis 
	cell_defaults.phenotype.death.rates[necrosis_model_index] = 0.0; 
	cell_defaults.phenotype.death.rates[apoptosis_model_index ] = 0.0; 

	// set oxygen uptake / secretion parameters for the default cell type 
	//cell_defaults.phenotype.secretion.uptake_rates[oxygen_substrate_index] = 10; 
	//cell_defaults.phenotype.secretion.secretion_rates[oxygen_substrate_index] = 0; 
	//cell_defaults.phenotype.secretion.saturation_densities[oxygen_substrate_index] = 38; 
	
	// add custom data here, if any 
	

	// Now, let's define another cell type. 
	// It's best to just copy the default and modify it. 
	
	// make this cell type randomly motile, less adhesive, greater survival, 
	// and less proliferative 
	
	CellA = cell_defaults; 
	CellA.type = 1; 
	CellA.name = "ModelCell"; 
	
	// make sure the new cell type has its own reference phenotype
	
	CellA.parameters.pReference_live_phenotype = &( CellA.phenotype ); 
	//cell
	// enable random motility 
	CellA.phenotype.motility.is_motile = false; 
	//CellA.phenotype.geometry.radius=100;
	//CellA.phenotype.motility.persistence_time = parameters.doubles( "CellA_persistence_time" ); // 15.0; 
	//CellA.phenotype.motility.migration_speed = parameters.doubles( "CellA_migration_speed" ); // 0.25 micron/minute 
	//CellA.phenotype.motility.migration_bias = 0.0;// completely random 
	
	// Set cell-cell adhesion to 5% of other cells 
	//CellA.phenotype.mechanics.cell_cell_adhesion_strength *= parameters.doubles( "CellA_relative_adhesion" ); // 0.05; 
	
	// Set apoptosis to zero 
	//CellA.phenotype.death.rates[apoptosis_model_index] = parameters.doubles( "CellA_apoptosis_rate" ); // 0.0; 
	
	// Set proliferation to 10% of other cells. 
	// Alter the transition rate from G0G1 state to S state
	CellA.phenotype.cycle.data.transition_rate(0,0) *= 0;
		//parameters.doubles( "CellA_relative_cycle_entry_rate" ); // 0.1; 
	//std::cout<<"set up micro types";
	return; 
}

void setup_microenvironment( void )
{
	// set domain parameters 
	
/*now this is in XML 
	default_microenvironment_options.X_range = {PhysiCell_settings.x_min, PhysiCell_settings.domain.x_min}; 
	default_microenvironment_options.Y_range = {-1000, 1000}; 
	default_microenvironment_options.simulate_2D = true; 
*/
	
	// make sure to override and go back to 2D 
	if( default_microenvironment_options.simulate_2D == false )
	{
		std::cout << "Warning: overriding XML config option and setting to 2D!" << std::endl; 
		default_microenvironment_options.simulate_2D = true; 
	}
	
/* now this is in XML 	
	// no gradients need for this example 

	default_microenvironment_options.calculate_gradients = false; 
	
	// set Dirichlet conditions 

	default_microenvironment_options.outer_Dirichlet_conditions = true;
	
	// if there are more substrates, resize accordingly 
	std::vector<double> bc_vector( 1 , 38.0 ); // 5% o2
	default_microenvironment_options.Dirichlet_condition_vector = bc_vector;
	
	// set initial conditions 
	default_microenvironment_options.initial_condition_vector = { 38.0 }; 
*/
    initialize_microenvironment();
	// put any custom code to set non-homogeneous initial conditions or 
	// extra Dirichlet nodes here. 
	
	// initialize BioFVM 
	bool make_Dirichlet_right=parameters.bools("Apply_Dirichlet_on_right_edge");
	bool make_Dirichlet_left=parameters.bools("Apply_Dirichlet_on_left_edge");
	bool make_Dirichlet_top=parameters.bools("Apply_Dirichlet_on_top_edge");
	bool make_Dirichlet_bottom=parameters.bools("Apply_Dirichlet_on_bottom_edge");
	if (make_Dirichlet_top==true)
	{
        for( unsigned int k=0 ; k < microenvironment.mesh.z_coordinates.size() ; k++ )
		{
			// set Dirichlet conditions along the 4 outer edges 
			for( unsigned int i=0 ; i < microenvironment.mesh.x_coordinates.size() ; i++ )
			{
				//int J = microenvironment.mesh.y_coordinates.size()-1;
				microenvironment.add_dirichlet_node( microenvironment.voxel_index(i,0,k) , default_microenvironment_options.Dirichlet_condition_vector );
				//microenvironment.add_dirichlet_node( microenvironment.voxel_index(i,J,k) , default_microenvironment_options.Dirichlet_condition_vector );
			}
			
		}
	}
	if (make_Dirichlet_bottom==true)
	{
				for( unsigned int k=0 ; k < microenvironment.mesh.z_coordinates.size() ; k++ )
		{
			// set Dirichlet conditions along the 4 outer edges 
			for( unsigned int i=0 ; i < microenvironment.mesh.x_coordinates.size() ; i++ )
			{
				int J = microenvironment.mesh.y_coordinates.size()-1;
				//microenvironment.add_dirichlet_node( microenvironment.voxel_index(i,0,k) , default_microenvironment_options.Dirichlet_condition_vector );
				microenvironment.add_dirichlet_node( microenvironment.voxel_index(i,J,k) , default_microenvironment_options.Dirichlet_condition_vector );
			}
				
		}
		
	}
	if (make_Dirichlet_left==true)
	{
				for( unsigned int k=0 ; k < microenvironment.mesh.z_coordinates.size() ; k++ )
		{
			// set Dirichlet conditions along the 4 outer edges 
			int I = microenvironment.mesh.x_coordinates.size()-1;
			for( unsigned int j=1; j < microenvironment.mesh.y_coordinates.size()-1 ; j++ )
			{
				microenvironment.add_dirichlet_node( microenvironment.voxel_index(0,j,k) , default_microenvironment_options.Dirichlet_condition_vector );
				//microenvironment.add_dirichlet_node( microenvironment.voxel_index(I,j,k) , default_microenvironment_options.Dirichlet_condition_vector );
			}		
		}
	}
	if (make_Dirichlet_right==true)
	{
		for( unsigned int k=0 ; k < microenvironment.mesh.z_coordinates.size() ; k++ )
		{
			// set Dirichlet conditions along the 4 outer edges 
			int I = microenvironment.mesh.x_coordinates.size()-1;
			for( unsigned int j=1; j < microenvironment.mesh.y_coordinates.size()-1 ; j++ )
			{
				//microenvironment.add_dirichlet_node( microenvironment.voxel_index(0,j,k) , default_microenvironment_options.Dirichlet_condition_vector );
			microenvironment.add_dirichlet_node( microenvironment.voxel_index(I,j,k) , default_microenvironment_options.Dirichlet_condition_vector );
			}		
		}
		
		
	}
	
	

	bool make_Dirichlet_node=parameters.bools("make_Dirichlet_node");
	
	
if (make_Dirichlet_node==true)
{
	std::vector<double> bc_vector( 2 );
	bc_vector[0]=parameters.doubles("Concentration_of_oxygen");//getvalue
	bc_vector[1]=parameters.doubles("Concentration_of_Chemical_A");//getvalue
	double x= parameters.doubles("Dirichlet_node_position_x");//getx vale:
	double y=  parameters.doubles("Dirichlet_node_position_y");//get yvalue
	std::vector<double> position(2);
	position[0]= x;
	position[1]= y;
	int voxel= microenvironment.nearest_voxel_index( position);
	microenvironment.add_dirichlet_node( voxel,bc_vector );
//double x=
	
} 	
	
	return; 
}

void setup_tissue( void )
{
	// create some cells near the origin
	
	Cell* pC;

	pC = create_cell(CellA); 
	pC->assign_position( 0.0, 0.0, 0.0 );


	
	return; 
}

std::vector<std::string> my_coloring_function( Cell* pCell )
{
	// start with flow cytometry coloring 
	
	std::vector<std::string> output = false_cell_coloring_cytometry(pCell); 
		
	if( pCell->phenotype.death.dead == false && pCell->type == 1 )
	{
		 output[0] = "blue"; 
		 output[2] = "blue"; 
	}
	
	return output; 
}
