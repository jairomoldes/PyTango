/*******************************************************************************

   This file is part of PyTango, a python binding for Tango

   http://www.tango-controls.org/static/PyTango/latest/doc/html/index.html

   Copyright 2011 CELLS / ALBA Synchrotron, Bellaterra, Spain
   
   PyTango is free software: you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   PyTango is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Lesser General Public License for more details.
  
   You should have received a copy of the GNU Lesser General Public License
   along with PyTango.  If not, see <http://www.gnu.org/licenses/>.
   
*******************************************************************************/

#include "precompiled_header.hpp"
#include <tango.h>

struct PyLockerInfo
{
    static inline boost::python::object get_locker_id(Tango::LockerInfo &li)
    {
        return (li.ll == Tango::CPP) ?
            boost::python::object(li.li.LockerPid) :
            boost::python::tuple(li.li.UUID);
    }
};

void export_locker_info()
{
    boost::python::class_<Tango::LockerInfo>("LockerInfo")
        .def_readonly("ll", &Tango::LockerInfo::ll)
        .add_property("li", &PyLockerInfo::get_locker_id)
        .def_readonly("locker_host", &Tango::LockerInfo::locker_host)
        .def_readonly("locker_class", &Tango::LockerInfo::locker_class)
    ;
}