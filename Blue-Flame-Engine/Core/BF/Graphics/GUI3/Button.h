#pragma once
#include "BF/Graphics/GUI3/Widget.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			/** @file Button.h
			* A brief file description.
			* A more elaborated file description.
			*/
			/*! A test class */

			class BFE_API Button : public BF::Graphics::GUI::Widget<Button>
			{
			public:
				/** An enum type. 
				 *  The documentation block cannot be put after the enum! 
				*/
				enum class State { Normal, Pressed, Hovered, Released }; /**< enum value 1 */
				State state; /**< enum value 2 */

			public:
				Button(); //!< a Constructor
				~Button(); //!< a Destructor
			};
		}
	}
}