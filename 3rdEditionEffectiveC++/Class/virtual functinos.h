/*
The implementation of virtual functions requires that objects carry
information that can be used at runtime to determine which virtual
functions should be invoked on the object. This information typically
takes the form of a pointer called a vptr (“virtual table pointer”). The
vptr points to an array of function pointers called a vtbl (“virtual
table”); each class with virtual functions has an associated vtbl. When
a virtual function is invoked on an object, the actual function called is
determined by following the object’s vptr to a vtbl and then looking up
the appropriate function pointer in the vtbl.

*/
