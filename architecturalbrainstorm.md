# Architectural Brainstorm #

As simply as I can, I'm going to attempt to step through my conceptual map of how a game functions /from the player's point of view/. This should allow me to construct a game engine alongside debug visuals without too much confusion when it comes to organizing the relationship between the data, the framework, and the engine behind it.

On the face we have:
	- raw input from user

	who attempts to act on

	- GUI elements

	heard by

	- event listeners

	and translated by

	- engine code //super vague! what does this mean?
	- game data

	which performs changes on

	- game state
	- game data
	- GUI elements

	So let's list these out:

	:input handling => GUI arrangement model => ??engine code?? => game state, data.

	From the above, it looks like we need generic command translation - which might actually be a complex message system itself. And, given the fact that it's context-specific, the message system would have to be built into a sort of GUI-controller interface system.

	OK, so as an example, menus:

		Menu items would be stored as 'hot' areas that are clickable and might change their look when hovered over.

		
