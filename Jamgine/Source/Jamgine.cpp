#include <Jamgine/Include/Jamgine.h>
#include <Jamgine/Include/Shared.h>
#include <exception>

#include <Jamgine/Include/Implementation/JamgineImplementation.h>

namespace Jamgine
{
	
	JamgineEngine* JamgineEngine::m_jamgineEngine = nullptr;

	ErrorMessage JamgineEngine::CreateEngine(JamgineEngine** p_jamgineEngine, Subsystem p_subsystems,  GraphicalSystem p_graphicalSystem)
	{
		ErrorMessage l_errorMessage = J_OK;
		
		if(m_jamgineEngine == nullptr)
		{		
			if(p_graphicalSystem == GraphicalSystem::DIRECTX)
			{
				try{
					m_jamgineEngine = new JamgineImplementation();
				}
				catch(std::exception e)
				{
					l_errorMessage = J_FAIL;
				}
			}
			else if(p_graphicalSystem == GraphicalSystem::OPENGL)
			try{
					//m_jamgineEngine = new OpenGLEngine();
				}
				catch(std::exception e)
				{
					l_errorMessage = J_FAIL;
				}
		}
		*p_jamgineEngine = m_jamgineEngine;
		return l_errorMessage;
	}

	ErrorMessage JamgineEngine::ReleaseEngine()
	{
		ErrorMessage l_errorMessage = J_OK;
		if(m_jamgineEngine == nullptr)
			l_errorMessage = J_FAIL; 
		//else
		//{
		//	try
		//	{
		//	//	m_jamgineEngine->Safe_Delete(m_jamgineEngine);
		//	}
		//	catch(std::exception e)
		//	{
		//		l_errorMessage = ErrorMessage::FAILED; 
		//	}
		//}
		return l_errorMessage;
	}	
}