/*******************************************************************************
 * Copyright (c)  2015  Dipl.-Ing. Tobias Rohde, http://www.lobaro.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *******************************************************************************/

#include "liblobaro_coap.h"
#include "coap.h"
#include "coap_main.h"

void debugPuts_Empty(char* s) {

}

void CoAP_Init(CoAP_API_t api, CoAP_Config_t cfg) {
	CoAP.api = api;
	CoAP.cfg = cfg;

	// To make the tests stable, we should provide proper log functions in future
	if (CoAP.api.debugPuts == NULL) {
		CoAP.api.debugPuts = debugPuts_Empty;
	}

	INFO("CoAP_init!\r\n");
	INFO("CoAP Interaction size: %d byte\r\n", sizeof(CoAP_Interaction_t));
	INFO("CoAP_Res_t size: %d byte\r\n", sizeof(CoAP_Res_t));
	INFO("CoAP_Message_t size: %d byte\r\n", sizeof(CoAP_Message_t));
	INFO("CoAP_option_t size: %d byte\r\n", sizeof(CoAP_option_t));
	INFO("CoAP_Observer_t size: %d byte\r\n", sizeof(CoAP_Observer_t));

	coap_mem_init(cfg.Memory, cfg.MemorySize);
	CoAP_InitResources();
}
