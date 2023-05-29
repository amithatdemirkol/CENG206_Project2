#ifndef _ISCENE_H_
#define _ISCENE_H_

class IScene {

	public:

		virtual void Render() = 0;
		virtual void Hide() = 0;
};

#endif
