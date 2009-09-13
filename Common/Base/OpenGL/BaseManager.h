/*!
	@file
	@author		Albert Semenov
	@date		08/2008
	@module
*/
/*
	This file is part of MyGUI.
	
	MyGUI is free software: you can redistribute it and/or modify
	it under the terms of the GNU Lesser General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.
	
	MyGUI is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU Lesser General Public License for more details.
	
	You should have received a copy of the GNU Lesser General Public License
	along with MyGUI.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef __BASE_MANAGER_H__
#define __BASE_MANAGER_H__

#include <MyGUI.h>
#include <MyGUI_OpenGLPlatform.h>
#include "../StatisticInfo.h"

namespace base
{

	class BaseManager
	{
	public:
		static BaseManager & getInstance();

		BaseManager();
		~BaseManager();

		virtual void prepare(int argc, char **argv); // ������������� ���������� ������
		bool create(); // ������� ��������� ����� ������� ����������
		void destroy(); // ������� ��� ��������� ������� ����������
		void run();

		int getWidth() { return mWidth; }
		int getHeight() { return mHeight; }

		void addResourceLocation(const std::string & _name, bool _recursive = false);

		void setWindowCaption(const std::string & _text);
		void setWallpaper(const std::string & _filename);
		void setDescriptionText(const MyGUI::UString & _text);

		statistic::StatisticInfo * getStatisticInfo() { return mInfo; }

	protected:
		void createInput();
		void destroyInput();

		void createGui();
		void destroyGui();

		virtual void createScene() { }
		virtual void destroyScene() { }

		virtual void setupResources();

	protected:
		static BaseManager* m_instance;

		int mWidth, mHeight;

		MyGUI::Gui* mGUI;
		MyGUI::OpenGLPlatform* mPlatform;
		statistic::StatisticInfo* mInfo;
		std::string mRootMedia;
	};

} // namespace base

#endif // __BASE_MANAGER_H__
